#pragma once

#include "ofMain.h"

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

	// Inline Helpers
	void title();
		
};
