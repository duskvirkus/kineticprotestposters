#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks

void ofApp::setup(){
	backgroundColor = ofColor(255, 216, 0);
	circlesColor = ofColor(121, 2, 170);
	ofSetCircleResolution(1024);
}

void ofApp::update(){
	title();
}

void ofApp::draw(){
	ofBackground(backgroundColor);
	circleGrid(100 + sin(ofGetFrameNum() * 0.01) * ofGetWidth() / 10, 100, ofGetWidth() / 2, ofGetHeight() / 2, 5, 5);
}

//--------------------------------------------------------------
// Methods

void ofApp::circleGrid(int x, int y, int w, int h, int xNumber, int yNumber) {
	float scale = w > h ? w / xNumber : h / yNumber;
	for (int i = 0; i < xNumber; i++) {
		for (int j = 0; j < yNumber; j++) {
			intersexCircle(x + (i * scale), y + (j * scale), scale / 3);
		}
	}
}

//--------------------------------------------------------------
// Inline Helpers

inline void ofApp::title() {
	stringstream titleStream;
	titleStream << PROJECT_NAME << " - " << CREATOR << " - FPS: " << static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());
}

inline void ofApp::intersexCircle(int x, int y, int radius) {
	ofSetColor(circlesColor);
	ofDrawCircle(x, y, radius);
	ofSetColor(backgroundColor);
	ofDrawCircle(x, y, radius * 3 / 4);
}