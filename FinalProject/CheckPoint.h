#ifndef CHECKPOINT_H
#define	CHECKPOINT_H

#include <iostream>
#include <cmath>

//int Cpoints[8][2] = { 270,  370,  1270,  430,  1380, 2420, 1800, 2460,
                     //1850, 1700,  2500, 1680,  2150, 3200,  370, 3200, };

struct CheckPoint
{
	float bounce =0;
	int xp = 0;
	int yp = 0;
	int oyp = 0;

	CheckPoint()
	{
	}

	CheckPoint(int a, int b)
	{
		xp=a;
		yp=b;
		oyp = b;
	}

	void hover()
	{
		bounce=bounce+.05;
		if ((bounce+1)>(std::numeric_limits<float>::max())){bounce=0;}
		yp = oyp +(std::sin(bounce)*8);
	}

};







#endif	