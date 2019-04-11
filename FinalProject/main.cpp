#include <cmath>

#include <SFML/Graphics.hpp>
#include "Car.h"
#include "CheckPoint.h"
#include <random>
#include <time.h>
#include <limits> // Just to get an exact value for max float size

using namespace sf;

//int Cpoints[8][2] = { 270,  370,  1270,  430,  1380, 2420, 1800, 2460,
 //                    1850, 1700,  2500, 1680,  2150, 3200,  370, 3200, };


int
main()
{
  RenderWindow app(VideoMode(1280, 960), "Car Racing Game!");
  app.setFramerateLimit(60);

  Texture t1, t2, t3;
  t1.loadFromFile("images/background.png");
  t2.loadFromFile("images/car.png");
  t3.loadFromFile("images/CheckPoint.png");
  t1.setSmooth(true);
  t2.setSmooth(true);
  t3.setSmooth(true);

  Sprite sBackground(t1), sCar(t2), sCheck(t3);
  sBackground.scale(2, 2);
  sCheck.setScale(.3,.3);

  sCar.setOrigin(22, 22);
  float R = 22;


  Car Player;
  Car Easy;
  Car Med;
  Car Hard;
  Car Wowzers;


  Car Holder[5] = {Player,Easy,Med,Hard,Wowzers};

  CheckPoint Checks[8];

  Checks[0] = CheckPoint(270,370);
  Checks[1] = CheckPoint(1270,430);
  Checks[2] = CheckPoint(1380,2420);
  Checks[3] = CheckPoint(1800,2460);
  Checks[4] = CheckPoint(1850,1700);
  Checks[5] = CheckPoint(2500,1680);
  Checks[6] = CheckPoint(2150,3200);
  Checks[7] = CheckPoint(370,3200);

  float bounce = 0;
  float speed = 0, angle = 0;
  float maxSpeed = 12.0;
  float acc = 0.2, dec = 0.3;
  float turnSpeed = 0.06;

  int currentCP = 0;

  for (int i = 0; i < 5; i++) {
    Holder[i].x = 300 + i * 50;
    Holder[i].y = 1700 + i * 80;
    Holder[i].speed = 7 + i;
  }


  int offsetX = 0, offsetY = 0;

  while (app.isOpen()) {
    Event e;
    while (app.pollEvent(e)) {
      if (e.type == Event::Closed)
        app.close();
    }

    bool Up = 0, Right = 0, Down = 0, Left = 0;
    if (Keyboard::isKeyPressed(Keyboard::Up))
      Up = 1;
    if (Keyboard::isKeyPressed(Keyboard::Right))
      Right = 1;
    if (Keyboard::isKeyPressed(Keyboard::Down))
      Down = 1;
    if (Keyboard::isKeyPressed(Keyboard::Left))
      Left = 1;

    // car movement
    if (Up && speed < maxSpeed) {
      if (speed < 0)
        speed += dec;
      else
        speed += acc;
    }

    if (Down && speed > -maxSpeed) {
      if (speed > 0)
        speed -= dec;
      else
        speed -= acc;
    }

    if (!Up && !Down) {
      if (speed - dec > 0)
        speed -= dec;
      else if (speed + dec < 0)
        speed += dec;
      else
        speed = 0;
    }

    if (Right && speed != 0)
      angle += turnSpeed * speed / maxSpeed;
    if (Left && speed != 0)
      angle -= turnSpeed * speed / maxSpeed;

    Holder[0].speed = speed;
    Holder[0].angle = angle;


    for (int i = 0; i < 5; i++)
      Holder[i].move();
    for (int i = 1; i < 5; i++)
      Holder[i].findTarget();

    
    for (int a = 0; a < 5; a++)
    {
      for (int b = 0; b < 5; b++)
      {

        int dx = 0, dy = 0;
        while (dx * dx + dy * dy < 4 * R * R) 
        {
          Holder[a].x += dx / 10.0;
          Holder[a].x += dy / 10.0;
          Holder[b].x -= dx / 10.0;
          Holder[b].y -= dy / 10.0;
          dx = Holder[a].x - Holder[b].x;
          dy = Holder[a].y - Holder[b].y;
          if (!dx && !dy){break;}
        }
      }
    }

    app.clear(Color::White);


    if (Holder[0].x > 320)
      offsetX = Holder[0].x - 320;
    if (Holder[0].y > 240)
      offsetY = Holder[0].y - 240;

    sBackground.setPosition(-offsetX, -offsetY);

    app.draw(sBackground);

    Color colors[10] = 
    {
      Color::Red, 
      Color::Green, 
      Color::Magenta, 
      Color::Blue, 
      Color::White,
      Color::Black,
      Color::Yellow,
      Color::Cyan,
      Color::Transparent,
    };

    Color cpColors[3] =
    {
      Color::Blue,
      Color::Black,
      Color::Cyan,
    };


    for(int i=0;i<8;i++)
    {
      Checks[i].hover();
      sCheck.setPosition(Checks[i].xp-offsetX,Checks[i].yp-offsetY);
      sCheck.setColor(cpColors[rand()%3]);
      app.draw(sCheck);
    }

    //Hyper-simplified method of figuring out locations on this map

    /*for (int i=0;i<8;i++)
    {

      float tx = Cpoints[i][0] -offsetX;
      float ty = Cpoints[i][1] -offsetY;
      sCheck.setScale(.3,.3);
      sCheck.setPosition(tx,ty+(std::sin(bounce))*8);
      sCheck.setRotation(0);
      sCheck.setColor(cpColors[rand()%3]);
      app.draw(sCheck);
    }

    bounce=bounce+.05;
    if ((bounce+1)>(std::numeric_limits<float>::max())){bounce=0;}
    */

    //-------------------------------------------------------------

    for (int i = 0; i < 5; i++) {
      sCar.setPosition(Holder[i].x - offsetX, Holder[i].y - offsetY);
      sCar.setRotation(Holder[i].angle * 180 / 3.141593);
      sCar.setColor(colors[i]);
      if (i==4)
      {
        srand(time(NULL));
        sCar.setColor(colors[rand()%9]);
      }
      app.draw(sCar);
    }

    app.display();
  }

  return 0;
}
