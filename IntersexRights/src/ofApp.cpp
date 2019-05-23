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
	circleGrid(200, 200, ofGetWidth() / 2, ofGetHeight() / 2, 5, 5);
}

//--------------------------------------------------------------
// Methods

void ofApp::circleGrid(int x, int y, int w, int h, int xNumber, int yNumber) {
	vector<CircleData> circles;
	float scale = w > h ? w / xNumber : h / yNumber;
	float maxSize = sqrt(scale/2 * scale/2 + scale/2 * scale/2);
	for (int i = - 1; i <= xNumber; i++) {
		for (int j = - 1; j <= yNumber; j++) {
			if ((i + j * (xNumber + 2)) % 2 == 0) {
				circles.push_back(CircleData(
					x + (i * scale),
					y + (j * scale),
					ofMap(ofNoise(ofGetFrameNum() * 0.005, i, j), 0, 1, maxSize / 2, maxSize)
				));
				//intersexCircle(x + (i * scale), y + (j * scale), scale / 3);
			}
		}
	}
	circlePack(circles, xNumber);
}

void ofApp::circlePack(vector<CircleData> everyOther, int width) {
	for (int i = 0; i < everyOther.size(); i++) {
		intersexCircle(everyOther[i].x, everyOther[i].y, everyOther[i].radius);
	}
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