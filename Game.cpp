#include "Game.h"

void Game::draw()
{
  m_food->draw();
  m_snake->draw();
  _display->display();
}

void Game::initialize(Adafruit_PCD8544* display,Snake* snake,Food* food)
{
  _display=display;
  m_snake=snake;
  m_food=food;
  m_snake->initialize(_display);
  m_food->initialize(_display);
}

void Game::checkForFoodCollision()
{
  if(m_snake->getHeadX()==m_food->getX() && m_snake->getHeadY()==m_food->getY())
  {
    m_snake->addUnit(m_food->getX(),m_food->getY());
    m_food->randomizePosition();
  }
}

void Game::gameLoop(const TailUnit::Direction& dir)
{
  
  checkForFoodCollision();
  m_snake->handleMovement(dir);
  m_snake->draw();
  m_food->draw();
  _display->display();
}

Snake* Game::getSnake()
{
  return m_snake;
}

Food* Game::getFood()
{
  return m_food;
}