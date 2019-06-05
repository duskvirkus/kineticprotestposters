#pragma once

#include "ofMain.h"
#include "ofxBDF.h"
#include "CircleGrid.h"
#include "CircleData.h"
#include "NumberOfFrames.h"

#define PROJECT_NAME "IntersexRights"
#define CREATOR	"Fi Graham"
#define SAVE_FRAMES false

class ofApp : public ofBaseApp{

public:

	ofColor backgroundColor;
	ofColor circlesColor;

	ofxBDF font;

	vector<CircleGrid> line1;
	vector<CircleGrid> line2;

	// openFrameworks
	void setup();
	void update();
	void draw();

	// Methods
	vector<CircleGrid> circleGridsFromText(string text);
	void updateLine(vector<CircleGrid>& line);
	void drawLine(vector<CircleGrid>& line, float x, float y);
	void drawLine(vector<CircleGrid>& line, float x, float y, int iterations);

	#if SAVE_FRAMES
	// Saving
	ofFbo fbo;
	unsigned int saveCount = 0;
	unsigned char skipFactor = 4;
	void saveFrame();
	#endif


	// Inline Helpers
	void title();
	void intersexCircle(float x, float y, float radius);
		
};
