#include <cmath>

#include <SFML/Graphics.hpp>
#include "Car.h"
#include "Holder.h"

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

  int spawn = 0;

  Car Player;
  Car Easy;
  Car Med;
  Car Hard;

  Holder g
  {
    Player,
    Easy,
    Med,
    Hard,
  };

  for (Car c : g)
  {
    c.x = 300 + spawn * 50;
    c.y = 1700 + spawn * 80;
    c.speed = 7 + spawn;
    spawn++;
  }

  /*for (int i = 1; i < N; i++) {
    cars[i].x = 300 + i * 50;
    cars[i].y = 1700 + i * 80;
    cars[i].speed = 7 + i;
  }
  */

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

    for (Car c : g)
    {
      c.move();
    }
    for (Car c : g)
    {
      if (c.isN == true)
      {
        //c.findTarget();
      }
    }

    /*for (int i = 0; i < N; i++)
      cars[i].move();
    for (int i = 1; i < N; i++)
      cars[i].findTarget();
    */
    // collision
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        int dx = 0, dy = 0;
        while (dx * dx + dy * dy < 4 * R * R) {
          cars[i].x += dx / 10.0;
          cars[i].x += dy / 10.0;
          cars[j].x -= dx / 10.0;
          cars[j].y -= dy / 10.0;
          dx = cars[i].x - cars[j].x;
          dy = cars[i].y - cars[j].y;
          if (!dx && !dy)
            break;
        }
      }

    app.clear(Color::White);

    if (cars[0].x > 320)
      offsetX = cars[0].x - 320;
    if (cars[0].y > 240)
      offsetY = cars[0].y - 240;

    sBackground.setPosition(-offsetX, -offsetY);
    app.draw(sBackground);

    Color colors[10] = {
      Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White
    };

    for (int i = 0; i < N; i++) {
      sCar.setPosition(cars[i].x - offsetX, cars[i].y - offsetY);
      sCar.setRotation(cars[i].angle * 180 / 3.141593);
      sCar.setColor(colors[i]);
      app.draw(sCar);
    }

    app.display();
  }

  return 0;
}