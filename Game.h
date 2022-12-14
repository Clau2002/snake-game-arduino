#ifndef Game_h
#define Game_h
#include "Snake.h"
#include "Food.h"
class Game
{
public:
Adafruit_PCD8544* _display;
void draw();
void initialize(Adafruit_PCD8544* display,Snake* snake,Food* food);
void reset();
void checkForFoodCollision();
void gameLoop(const TailUnit::Direction& dir);

Snake* getSnake();
Food* getFood();
private:
Snake* m_snake;
Food* m_food;
};
#endif