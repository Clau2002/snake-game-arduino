#include <SPI.h>
#include "Game.h"
#include "Movement.h"
// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
Game game;
TailUnit::Direction dir=TailUnit::Direction::E_RIGHT;
int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
void setup() {
  
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  display.begin();
  Snake* snake=new Snake();
  Food* food=new Food();
  game.initialize(&display,snake,food);
  display.setContrast(40); 
  display.setBias(5);
  randomSeed(analogRead(0));
}

TailUnit::Direction placeholderRandom()
{
  TailUnit::Direction currentDir=game.getSnake()->getDirection();
  if(currentDir==TailUnit::Direction::E_DOWN)
  return TailUnit::Direction::E_LEFT;
  if(currentDir==TailUnit::Direction::E_UP)
  return TailUnit::Direction::E_RIGHT;
  if(currentDir==TailUnit::Direction::E_LEFT)
  return TailUnit::Direction::E_DOWN;
  if(currentDir==TailUnit::Direction::E_RIGHT)
  return TailUnit::Direction::E_UP;
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  display.fillRect(0,0,WIDTH,HEIGHT,BLACK);
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
    int rand=random(10);
  Serial.print(rand);
  if(rand==7)
     dir=placeholderRandom();
  
  Movement m;
  m.mapMovement(mapX,mapY);
  switch(m.getMove())
  {
    case Movement::Move::RIGHT:
     game.gameLoop(TailUnit::Direction::E_RIGHT);
     break;
    case Movement::Move::LEFT:
     game.gameLoop(TailUnit::Direction::E_LEFT);
     break;
     case Movement::Move::UP:
     game.gameLoop(TailUnit::Direction::E_UP);
     break;
     case Movement::Move::DOWN:
     game.gameLoop(TailUnit::Direction::E_DOWN);
     break;
     default:
     game.gameLoop(TailUnit::Direction::E_UP);
     break;
  }
  
  
  delay(300);
  display.clearDisplay();
}
