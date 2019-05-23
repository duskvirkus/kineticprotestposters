#pragma once

#include "ofMain.h"
#include "CircleData.h"

#define PROJECT_NAME "IntersexRights"
#define CREATOR	"Fi Graham"
#define SAVE_FRAMES false

class ofApp : public ofBaseApp{

public:

	ofColor backgroundColor;
	ofColor circlesColor;

	// openFrameworks
	void setup();
	void update();
	void draw();

	// Methods
	void circleGrid(int x, int y, int w, int h, int xNumber, int yNumber);
	void circlePack(vector<CircleData> everyOther, int width);

	// Inline Helpers
	void title();
	void intersexCircle(float x, float y, float radius);
		
};
