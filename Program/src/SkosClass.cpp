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
  if(isLabelAlreadyExists(p_prefLabel))
  {
    qDebug() << "SkosClass::isPrefLabelOk() - label already exists";
  }
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

void SkosClass::addPrefLabel(Soprano::Node p_prefLabel)
{
  qDebug() << "SkosClass::addPrefLabel(p_prefLabel="
           << p_prefLabel.toString() << ")";
  if (isPrefLabelOk(p_prefLabel))
  {
    m_prefLabels.append(p_prefLabel);
  }
}

void SkosClass::addAltLabel(Soprano::Node p_altLabel)
{
  qDebug() << "SkosClass::addAltLabel(p_altLabel="
           << p_altLabel.toString() << ")";
  if (isLabelAlreadyExists(p_altLabel))
  {
    qDebug() << "SkosClass::addAltLabel() - label already exists";
  }
  {
    m_altLabels.append(p_altLabel);
  }
}

void SkosClass::addHiddenLabel(Soprano::Node p_hiddenLabel)
{
  qDebug() << "SkosClass::addHiddenLabel(p_hiddenLabel="
           << p_hiddenLabel.toString() << ")";
  if (isLabelAlreadyExists(p_hiddenLabel))
  {
    qDebug() << "SkosClass::addHiddenLabel() - label already exists";
  }
  {
    m_hiddenLabels.append(p_hiddenLabel);
  }
}
