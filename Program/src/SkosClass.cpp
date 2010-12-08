#include "SkosClass.hpp"

#include <QDebug>

QUrl SkosClass::getUrl() const
{
  return m_url;
}

void SkosClass::setUrl(const QUrl &p_url)
{
  m_url = p_url;
}

bool SkosClass::isLabelAlreadyExists(const Soprano::Node &p_label)
{
  qDebug() << "SkosClass::isLabelAlreadyExists(p_label="
           << p_label.toString() << ")";
  return((findLabel(p_label, m_prefLabels) != m_prefLabels.end()) &&
         (findLabel(p_label, m_altLabels) != m_altLabels.end()) &&
         (findLabel(p_label, m_hiddenLabels) != m_hiddenLabels.end()));
}

bool SkosClass::isPrefLabelOk(const Soprano::Node &p_prefLabel) const
{
  qDebug() << "SkosClass::isPrefLabelOk(p_prefLabel="
           << p_prefLabel.toString() << ")";
  for(QList<Soprano::Node>::const_iterator l_iter = m_prefLabels.begin();
      l_iter != m_prefLabels.end(); ++l_iter)
  {
    if (l_iter->language() == p_prefLabel.language())
    {
      qDebug() << "SkosClass::isPrefLabelOk() - prefered label in this"
               << "language already exists";
      return false;
    }
  }
  return true;
}

void SkosClass::addLabel(Soprano::Node p_label, 
                         const ELabelType &p_labelType)
{
  qDebug() << "SkosClass::addLabel(p_prefLabel =" << p_label.toString()
           << ", p_labelType =" << p_labelType << ")";
  if (isLabelAlreadyExists(p_label))
  {
    qDebug() << "SkosClass::addLabel() - this label already exists for this"
             << "class";
  }
  else
  {
    switch (p_labelType)
    {
      case PrefferedLabelType:
      {
        if(isPrefLabelOk(p_label))
        {
          addLabel(p_label, m_prefLabels);
        }
        break;
      }
      case AlternativeLabelType:
      {
        addLabel(p_label, m_altLabels);
        break;
      }
      case HiddenLabelType:
      {
        addLabel(p_label, m_hiddenLabels);
        break;
      }
    }      
  }
}

void SkosClass::removeLabel(const Soprano::Node &p_label, 
                            const ELabelType &p_labelType)
{
  qDebug() << "SkosClass::removeLabel(p_prefLabel =" << p_label.toString()
           << ", p_labelType =" << p_labelType << ")";
  switch (p_labelType)
  {
    case PrefferedLabelType:
    {
      removeLabel(p_label, m_prefLabels);
      break;
    }
    case AlternativeLabelType:
    {
      removeLabel(p_label, m_altLabels);
      break;
    }
    case HiddenLabelType:
    {
      removeLabel(p_label, m_hiddenLabels);
      break;
    }
  }      
}

void SkosClass::addLabel(Soprano::Node p_label,
                         QList<Soprano::Node> &p_labelList)
{
  qDebug() << "SkosClass::addLabel(p_label=" << p_label.toString()
           << ", p_labelList)";
  p_labelList.append(p_label);
}

void SkosClass::removeLabel(const Soprano::Node &p_label,
                            QList<Soprano::Node> &p_labelList)
{
  qDebug() << "SkosClass::removeLabel(p_label=" << p_label.toString()
           << ", p_labelList)";
  QList<Soprano::Node>::iterator l_iter = findLabel(p_label, p_labelList);
  if (l_iter == p_labelList.end())
  {
    qDebug() << "SkosClass::removeLabel() - no such label";
  }
  else
  {
    p_labelList.erase(l_iter);
    qDebug() << "SkosClass::removeLabel() - label removed";
  }
}

QList<Soprano::Node>::iterator SkosClass::findLabel(
  const Soprano::Node &p_label,
  QList<Soprano::Node> &p_labelList)
{
  qDebug() << "SkosClass::findLabel(p_label=" << p_label.toString()
           << ", p_labelList)";
  for (QList<Soprano::Node>::iterator l_iter = p_labelList.begin();
       l_iter != p_labelList.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return l_iter;
    }
  }
  return p_labelList.end();
}

QList<Soprano::Node> SkosClass::getLabelList(
  const ELabelType &p_labelType) const
{
  qDebug() << "SkosClass::getLabelList(p_labelType=" << p_labelType << ")";
  switch (p_labelType)
  {
    case PrefferedLabelType:
    {
      return m_prefLabels;
    }
    case AlternativeLabelType:
    {
      return m_altLabels;
    }
    case HiddenLabelType:
    {
      return m_hiddenLabels;
    }
  }
  return QList<Soprano::Node>();
}
