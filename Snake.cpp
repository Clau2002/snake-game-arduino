#include "Snake.h"

Snake::Snake()
{
  m_size = 3;
	m_headX = 0;
	m_headY = 0;
}

void Snake::initialize(Adafruit_PCD8544* display)
{
  _display=display;
  initializeTailUnits();
}

void Snake::handleMovement(TailUnit::Direction dir)
{
  m_direction=dir;
  TailUnit* tail=m_tailUnits[0];

  if(dir==TailUnit::Direction::E_LEFT)
   moveLeft(tail);
  if(dir==TailUnit::Direction::E_RIGHT)
   moveRight(tail);
  if(dir==TailUnit::Direction::E_UP)
   moveUp(tail);
  if(dir==TailUnit::Direction::E_DOWN)
   moveDown(tail);

  for(int i = 0;i<m_size-1;i++)
	{
		m_tailUnits[i]=m_tailUnits[i+1];
	}  
  m_tailUnits[m_size-1]=tail;
  m_headX=tail->getX();
  m_headY=tail->getY();
}


void Snake::initializeTailUnits()
{
  int start_x=36;
  int start_y=24;
  for(int i=0;i<m_size;i++)
  {
     if(i==0)
     {
       TailUnit* newUnit=new TailUnit(start_x,start_y,TailUnit::Direction::E_NONE);
       m_tailUnits[i]=newUnit;
     }
     else
     {
       TailUnit* newUnit=new TailUnit(m_tailUnits[i-1]->getX()+2,m_tailUnits[i-1]->getY(),TailUnit::Direction::E_NONE);
       m_tailUnits[i]=newUnit;
     }
     
  }
}

void Snake::moveLeft(TailUnit *unit)
{
  if(m_tailUnits[m_size-1]->getX()+TailUnit::_size != WIDTH)
  {
    unit->setX(m_tailUnits[m_size-1]->getX()+TailUnit::_size);
    unit->setY(m_tailUnits[m_size-1]->getY());
  }
  else
  {
    unit->setX(0);
    unit->setY(m_tailUnits[m_size-1]->getY());
  }
}

void Snake::moveRight(TailUnit *unit)
{
  if(m_tailUnits[m_size-1]->getX() != 0)
  {
    unit->setX(m_tailUnits[m_size-1]->getX()-TailUnit::_size);
    unit->setY(m_tailUnits[m_size-1]->getY());
  }
  else
  {
    unit->setX(WIDTH-TailUnit::_size);
    unit->setY(m_tailUnits[m_size-1]->getY());
  }
}

void Snake::moveDown(TailUnit *unit)
{
  if(m_tailUnits[m_size-1]->getY()!=0)
  {
    unit->setX(m_tailUnits[m_size-1]->getX());
    unit->setY(m_tailUnits[m_size-1]->getY()-TailUnit::_size);
  }
  else
  {
    unit->setX(m_tailUnits[m_size-1]->getX());
    unit->setY(HEIGHT-TailUnit::_size);
  }
}

void Snake::moveUp(TailUnit *unit)
{
  if(m_tailUnits[m_size-1]->getY()+TailUnit::_size != HEIGHT)
  {
    unit->setX(m_tailUnits[m_size-1]->getX());
    unit->setY(m_tailUnits[m_size-1]->getY()+TailUnit::_size);
  }
  else
  {
    unit->setX(m_tailUnits[m_size-1]->getX());
    unit->setY(0);
  }
}

const TailUnit::Direction& Snake::getDirection() const
{
  return m_direction;
}

void Snake::addUnit(int x, int y)
{
  if(m_size<_sizeMAX)
  {
    TailUnit* unit=new TailUnit(x,y,TailUnit::Direction::E_NONE);
    unit->setX(x);
    unit->setY(y);
    m_headX=x;
    m_headY=y;
    m_size++;
    m_tailUnits[m_size-1]=unit;
  }
}

void Snake::draw(){
  for (int i = 0; i < m_size; i ++) {
		_display->fillRect(m_tailUnits[i]->getX(), m_tailUnits[i]->getY(), TailUnit::_size, TailUnit::_size, WHITE);
	}
}

const int& Snake::getHeadX() const
{
  return m_headX;
}

const int& Snake::getHeadY() const
{
  return m_headY;
}