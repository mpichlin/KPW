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

bool SkosClass::isLabelAlreadyExists(const Soprano::Node &p_label) const
{
  qDebug() << "SkosClass::isLabelAlreadyExists(p_label="
           << p_label.toString() << ")";
  for (QList<Soprano::Node>::const_iterator l_iter = m_prefLabels.begin();
       l_iter != m_prefLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  for (QList<Soprano::Node>::const_iterator l_iter = m_altLabels.begin();
       l_iter != m_altLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  for (QList<Soprano::Node>::const_iterator l_iter = m_hiddenLabels.begin();
       l_iter != m_hiddenLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  return false;
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

void SkosClass::addLabel(Soprano::Node p_label,
                         QList<Soprano::Node> &p_labelList)
{
  qDebug() << "SkosClass::addLabel(p_label=" << p_label.toString()
           << ", p_labelList)";
  p_labelList.append(p_label);
}
