#include <cmath>

#include <SFML/Graphics.hpp>
#include "Car.h"

using namespace sf;


int
main()
{
  RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
  app.setFramerateLimit(60);

  Texture t1, t2, t3;
  t1.loadFromFile("images/background.png");
  t2.loadFromFile("images/car.png");
  t1.setSmooth(true);
  t2.setSmooth(true);

  Sprite sBackground(t1), sCar(t2);
  sBackground.scale(2, 2);

  sCar.setOrigin(22, 22);
  float R = 22;


  Car Player;
  Car Easy;
  Car Med;
  Car Hard;

  Car Holder[4] = {Player,Easy,Med,Hard};

  /*Player.NPC = false;

  Player.x = 350;
  Player.y = 1780;
  Player.speed = 7;

  Easy.x = 400;
  Easy.y = 1860;
  Easy.speed = 8;

  Med.x = 450;
  Med.y = 1940;
  Med.speed = 9;

  Hard.x = 500;
  Hard.y = 2020;
  Hard.speed = 10;*/

  for (int i = 0; i < 4; i++) {
    Holder[i].x = 300 + i * 50;
    Holder[i].y = 1700 + i * 80;
    Holder[i].speed = 7 + i;
  }


  float speed = 0, angle = 0;
  float maxSpeed = 12.0;
  float acc = 0.2, dec = 0.3;
  float turnSpeed = 0.08;

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

    Player.speed = speed;
    Player.angle = angle;


    /*Player.move();
    Easy.move();
    Med.move();
    Hard.move();
  
    Easy.findTarget();
    Med.findTarget();
    Hard.findTarget();
    */

    for (int i = 0; i < 4; i++)
      Holder[i].move();
    for (int i = 1; i < 4; i++)
      Holder[i].findTarget();

    
    for (int a = 0; a < 4; a++)
    {
      for (int b = 0; b < 4; b++)
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

    if (Player.x > 320)
      offsetX = Player.x - 320;
    if (Player.y > 240)
      offsetY = Player.y - 240;

    sBackground.setPosition(-offsetX, -offsetY);
    app.draw(sBackground);

    Color colors[10] = 
    {
      Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White
    };

    for (int i = 0; i < 4; i++) {
      sCar.setPosition(Holder[i].x - offsetX, Holder[i].y - offsetY);
      sCar.setRotation(Holder[i].angle * 180 / 3.141593);
      sCar.setColor(colors[i]);
      app.draw(sCar);
    }

    /*int color=0;
    for (Car c : g)
    {
      sCar.setPosition(c.x - offsetX, c.y - offsetY);
      sCar.setRotation(c.angle * 180 / 3.141593);
      sCar.setColor(colors[color]);
      app.draw(sCar);
      color++;
    }*/

    app.display();
  }

  return 0;
}
