#ifndef Snake_h
#define Snake_h

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "TailUnit.h"

class Snake
{
  public:
    Snake();
    static const int _sizeMAX=25;
    Adafruit_PCD8544* _display;
    void initialize(Adafruit_PCD8544* display);
    void initializeTailUnits();
    void addUnit(int x, int y);
    void handleMovement(TailUnit::Direction dir);
    void draw();

    void moveRight(TailUnit* unit);
    void moveLeft(TailUnit* unit);
    void moveUp(TailUnit* unit);
    void moveDown(TailUnit* unit);
    const TailUnit::Direction& getDirection() const;
    
    const int& getHeadX() const;
    const int& getHeadY() const;
  private:
    TailUnit* m_tailUnits[25];
    TailUnit::Direction m_direction;
    int m_size;
    int m_headX;
    int m_headY;
};
#endif