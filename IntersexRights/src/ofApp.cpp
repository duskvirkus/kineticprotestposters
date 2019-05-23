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
	for (int i = 0; i < (xNumber + 2) * (yNumber + 2); i++) {
		circles.push_back(CircleData());
	}
	float scale = w > h ? w / xNumber : h / yNumber;
	float maxSize = sqrt(scale/2 * scale/2 + scale/2 * scale/2);
	for (int i = 0; i < xNumber + 2; i++) {
		for (int j = 0; j < yNumber + 2; j++) {
			if ((i + j * (xNumber + 2)) % 2 == 0) {
				circles[i + j * (xNumber + 2)] = CircleData(
					x + ((i - 1) * scale),
					y + ((j - 1) * scale),
					ofMap(ofNoise(ofGetFrameNum() * 0.005, i - 1, j - 1), 0, 1, maxSize / 2, maxSize)
				);
			}
		}
	}
	for (int i = 1; i < xNumber + 1; i++) {
		for (int j = 1; j < yNumber + 1; j++) {
			if ((i + j * (xNumber + 2)) % 2 == 1) {
				float calcX = ofLerp(
					circles[i - 1 + j * (xNumber + 2)].x + circles[i - 1 + j * (xNumber + 2)].radius,
					circles[i + 1 + j * (xNumber + 2)].x - circles[i + 1 + j * (xNumber + 2)].radius,
					0.5
				);
				float calcY = ofLerp(
					circles[i + (j - 1) * (xNumber + 2)].y + circles[i + (j - 1) * (xNumber + 2)].radius,
					circles[i + (j + 1) * (xNumber + 2)].y - circles[i + (j + 1) * (xNumber + 2)].radius,
					0.5
				);
				circles[i + j * (xNumber + 2)] = CircleData(
					calcX,
					calcY,
					ofMap(ofNoise(ofGetFrameNum() * 0.005, i - 1, j - 1), 0, 1, maxSize / 2, maxSize)
				);
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