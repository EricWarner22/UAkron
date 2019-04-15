
#ifndef CAR_H
#define	CAR_H

#include <iostream>
#include <cmath>
#include <math.h>   

const int num = 8; // checkpoints
int points[num][2] = { 300,  610,  1270, 430,  1380, 2380, 1900, 2460,
                       1970, 1700, 2550, 1680, 2560, 3150, 500,  3300 };



struct Car 
{

	float x, y, speed, angle;
	int n;

	Car()
	{
		speed = 2;
		angle = 0;
		n = 0;
	}

	void move()
	{
		x += std::sin(angle) * speed;
		y -= std::cos(angle) * speed;
	}

	float findTarget(float nx, float ny,float tx, float ty, int & cp)
	{
		float dist = sqrt(((nx-tx)*(nx-tx)+(ny-ty)*(ny-ty)));
		/*float beta = angle - std::atan2(tx - x, -ty + y);
		if (std::sin(beta) < 0)
		  angle += 0.005 * speed;
		else
		  angle -= 0.005 * speed;*/
		if (dist < 105)
		  cp = (cp + 1) % num;

		return dist;
	}

	void findTarget()
	{
		float tx = points[n][0];
		float ty = points[n][1];
		float beta = angle - std::atan2(tx - x, -ty + y);
		if (std::sin(beta) < 0)
		  angle += 0.005 * speed;
		else
		  angle -= 0.005 * speed;
		if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25)
		  n = (n + 1) % num;
	}

};

#endif	


