#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks
void ofApp::setup() {
	// Initialize Global Variables
	textBlock.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.4, &blockTransRights);
	textBlock.setBounds(
		ofGetWidth()  * 0.4,
		ofGetWidth()  * 0.6,
		ofGetHeight() * 0.3,
		ofGetHeight() * 0.7
	);
	color1 = ofColor(91, 206, 250);
	color2 = ofColor(245, 169, 184);
	#if SAVE_FRAMES
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	#endif

	// Start Background
	#if SAVE_FRAMES
	fbo.begin();
	#endif
	ofBackground(255);
	#if SAVE_FRAMES
	fbo.end();
	#endif

	// Transparent Background
	color1.a = 8;
	color2.a = 8;
	ofSetBackgroundAuto(false);
}

void ofApp::update() {
	title();
	textBlock.update(ofVec2f(
		(sin(animationProgress() * PI * 4) + 1) / 2,
		(sin(animationProgress() * PI * 2) + 1) / 2
	));
}

void ofApp::draw() {
	#if SAVE_FRAMES
	fbo.begin();
	#endif

	transparentBackground(lerpColor(color1, color2, (sin(animationProgress() * TWO_PI) + 1) / 2));

	ofSetColor(255);
	textBlock.draw();

	#if SAVE_FRAMES
	fbo.end();
	fbo.draw(0, 0);
	if (ofGetFrameNum() % skipFactor == 0 && 
		ofGetFrameNum() >= framesInAnimation && 
		ofGetFrameNum() < framesInAnimation * 2) 
	{
		saveFrame();
	}
	#endif
}

#if SAVE_FRAMES
//--------------------------------------------------------------
// Saving

void ofApp::saveFrame() {
	ofImage grab;
	ofPixels pixels;
	fbo.getTexture().readToPixels(pixels);
	grab.setFromPixels(pixels);
	stringstream fileName;
	fileName << PROJECT_NAME << "-" << ofToString(saveCount, 4, '0') << ".png";
	grab.save(fileName.str());
	saveCount++;
}
#endif

//--------------------------------------------------------------
// Inline Helpers

inline void ofApp::title() {
	stringstream titleStream;
	titleStream << PROJECT_NAME << " - " << CREATOR << " - FPS: " << static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());
}

inline void ofApp::transparentBackground(ofColor color) {
	ofSetColor(color);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

inline ofColor ofApp::lerpColor(ofColor c1, ofColor c2, float amt) {
	ofColor c;
	c.r = ofLerp(c1.r, c2.r, amt);
	c.g = ofLerp(c1.g, c2.g, amt);
	c.b = ofLerp(c1.b, c2.b, amt);
	c.a = ofLerp(c1.a, c2.a, amt);
	return c;
}

float ofApp::animationProgress() {
	return (ofGetFrameNum() % framesInAnimation) / static_cast<float>(framesInAnimation);
}