#pragma once

#include "ofMain.h"
#include "CircleData.h"
#include "NumberOfFrames.h"

class CircleGrid {
public:
	
	vector<CircleData> circles;
	float width;
	float height;

	int columns;
	int rows;

	bool maskOn;
	vector<bool> mask;

	float noiseScale;
	float movementScale;
	float radiusScale;

	void setup(int columns, int rows, float width, float height);
	void applyMask(ofImage maskImage);
	void update();
	void scaleCircles(float scale);
	void draw(float x, float y);
	void draw(float x, float y, int iterations);

	int index(int x, int y, int w);

	string toString();

};

ostream& operator<<(ostream& os, CircleGrid cg);
