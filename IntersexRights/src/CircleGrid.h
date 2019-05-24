#pragma once

#include "ofMain.h"
#include "CircleData.h"

class CircleGrid {
public:
	
	vector<CircleData> circles;
	float width;
	float height;

	int columns;
	int rows;

	bool maskOn;
	vector<bool> mask;

	void setup(int columns, int rows, float width, float height);
	void update();
	void draw(float x, float y);

	int index(int x, int y, int w);

};

