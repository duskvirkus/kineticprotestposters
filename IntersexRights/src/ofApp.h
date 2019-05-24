#pragma once

#include "ofMain.h"
#include "CircleGrid.h"
#include "CircleData.h"

#define PROJECT_NAME "IntersexRights"
#define CREATOR	"Fi Graham"
#define SAVE_FRAMES false

class ofApp : public ofBaseApp{

public:

	ofColor backgroundColor;
	ofColor circlesColor;

	CircleGrid circleGrid;

	// openFrameworks
	void setup();
	void update();
	void draw();

	// Inline Helpers
	void title();
	void intersexCircle(float x, float y, float radius);
		
};
