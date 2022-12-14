#ifndef TailUnit_h
#define TailUnit_h

#define WIDTH 84
#define HEIGHT 48

class TailUnit
{
  public:
  static const int _size=2;
  enum class Direction
  {
    E_UP,
    E_DOWN,
    E_LEFT,
    E_RIGHT,
    E_NONE
  };
  TailUnit();
  TailUnit(int x, int y, Direction direction);
  const int& getX() const;
  const int& getY() const;
  void setX(const int& x);
  void setY(const int& y);
  private:
  int m_x;
  int m_y;
};

#endif