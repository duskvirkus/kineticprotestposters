#pragma once

#include "ofMain.h"
#include "FunctionTypes.h"

class TextBlock {

	public:

		int x;
		int y;
		int xMin;
		int xMax;
		int yMin;
		int yMax;
		int width;
		int height;
		int weight;

		DisplayFunction display;

		void setup(int width, int height, DisplayFunction display);
		void update(ofVec2f unscaledPosition);
		void draw();

		void setBounds(int xMin, int xMax, int yMin, int yMax);

};

