#ifndef Movement_h
#define Movement_h
class Movement
{
  public:
enum class Move 
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};
public:
 void mapMovement(const int& x, const int& y);
 const Move& getMove() const;
private:
Move m_Movement;
};
#endif