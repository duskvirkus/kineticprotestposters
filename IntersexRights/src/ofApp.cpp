#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks

void ofApp::setup(){
	backgroundColor = ofColor(255, 216, 0);
	circlesColor = ofColor(121, 2, 170);
	backgroundColor = ofColor(255);
	circlesColor = ofColor(0);
	ofSetCircleResolution(1024);

	circleGrid.setup(6, 10, 600, 600); // TODO fix sizing for even
}

void ofApp::update(){
	title();
	circleGrid.update();
}

void ofApp::draw(){
	ofBackground(backgroundColor);
	ofSetColor(0);
	circleGrid.draw(200, 200);
}

//--------------------------------------------------------------
// Inline Helpers

inline void ofApp::title() {
	stringstream titleStream;
	titleStream << PROJECT_NAME << " - " << CREATOR << " - FPS: " << static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());
}

inline void ofApp::intersexCircle(float x, float y, float radius) {
	ofSetColor(circlesColor);
	ofDrawCircle(x, y, radius);
	ofSetColor(backgroundColor);
	ofDrawCircle(x, y, radius * 3 / 4);
}