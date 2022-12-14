#include "TailUnit.h"

TailUnit::TailUnit()
{
  m_x=0;
  m_y=0;
}

TailUnit::TailUnit(int x,int y,TailUnit::Direction direction)
{
 m_x=x;
 m_y=y;
}

const int& TailUnit::getX() const
{
  return m_x;
}

const int& TailUnit::getY() const
{
  return m_y;
}

void TailUnit::setX(const int &x)
{
  m_x=x;
}

void TailUnit::setY(const int &y)
{
  m_y=y;
}