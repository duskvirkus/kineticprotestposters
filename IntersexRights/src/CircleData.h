#pragma once

#include "ofMain.h"

struct CircleData {
public:

	float x;
	float y;
	float radius;

	CircleData();
	CircleData(float x, float y, float radius);

	string toString();

};

ostream& operator<<(ostream& os, CircleData cd);
