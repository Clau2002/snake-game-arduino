#ifndef Food_h
#define Food_h

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class Food
{
  public:
  static const int _size=2;
  Food();
  Adafruit_PCD8544* _display;
  void initialize(Adafruit_PCD8544* display);
  void draw();
  void randomizePosition();
  const int& getX() const;
  const int& getY() const;
  private:
  int m_x;
  int m_y;
};
#endif