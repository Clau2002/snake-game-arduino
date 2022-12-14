#include "Food.h"

Food::Food()
{
  m_x=random(81);
  m_y=random(45);
}

void Food::initialize(Adafruit_PCD8544* display)
{
  _display=display;
}

void Food::draw()
{
  _display->fillRect(m_x,m_y,_size,_size,WHITE);
}

const int& Food::getX() const
{
 return m_x;
}

const int& Food::getY() const
{
 return m_y;
}

void Food::randomizePosition()
{
  m_x=random(82);
  m_y=random(45);
}