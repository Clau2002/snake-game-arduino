#include "Movement.h"

void Movement::mapMovement(const int& x, const int& y)
{
  if(y<512)
  {
  if(x==512)
    m_Movement=Movement::Move::LEFT;
    else if(x==-512)
    m_Movement=Movement::Move::RIGHT;
  }
   if(x<512)
  {
  if(y==512)
    m_Movement=Movement::Move::UP;
    else if(y==-512)
    m_Movement=Movement::Move::DOWN;
  }
}

const Movement::Move& Movement::getMove() const
{
  return m_Movement;
}