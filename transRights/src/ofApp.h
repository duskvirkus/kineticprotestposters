#pragma once

#include "ofMain.h"
#include "FunctionTypes.h"
#include "TextFunctions.h"
#include "TextBlock.h"

#define PROJECT_NAME "TransRights"
#define CREATOR	"Fi Graham"
#define SAVE_FRAMES false

class ofApp : public ofBaseApp{

	public:

		// Global Variables
		int framesInAnimation = 1200;
		ofColor color1, color2;
		TextBlock textBlock;

		// openFrameworks
		void setup();
		void update();
		void draw();
		
		#if SAVE_FRAMES
		// Saving
		ofFbo fbo;
		unsigned int saveCount = 0;
		unsigned char skipFactor = 4;
		void saveFrame();
		#endif

		// Inline Helpers
		void title();
		void transparentBackground(ofColor color);
		ofColor lerpColor(ofColor c1, ofColor c2, float amt);
		float animationProgress();

};