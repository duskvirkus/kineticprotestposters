#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		// openFrameworks
		void setup();
		void update();
		void draw();
		
		// Admin
		int framesInAnimation;
		ofFbo fbo;
		void title();
		void transparentBackground(ofColor color);
		float animationProgress();
		void saveFrame();

		// Text
		void blockTransRights(ofVec2f position, ofVec2f dimensions, int weight);
		void blockTransRights(int x, int y, int w, int h, int weight);
		void blockT(int x, int y, int w, int h, int weight);
		void blockR(int x, int y, int w, int h, int weight);
		void blockA(int x, int y, int w, int h, int weight);
		void blockN(int x, int y, int w, int h, int weight);
		void blockS(int x, int y, int w, int h, int weight);
		void blockI(int x, int y, int w, int h, int weight);
		void blockG(int x, int y, int w, int h, int weight);
		void blockH(int x, int y, int w, int h, int weight);

		// Color
		ofColor color1, color2;
		void setupColors();
		void setColorsAlpha(int a);
		ofColor lerpColor(ofColor c1, ofColor c2, float amt);
};
