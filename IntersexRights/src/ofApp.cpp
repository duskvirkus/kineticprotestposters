#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks

void ofApp::setup(){

	font.setup("../cherry/cherry-10-r.bdf");

	line1 = circleGridsFromText("INTERSEX");
	line2 = circleGridsFromText("RIGHTS");

	backgroundColor = ofColor(255, 216, 0);
	circlesColor = ofColor(121, 2, 170);
	ofSetCircleResolution(1024);

}

void ofApp::update(){

	title();
	updateLine(line1);
	updateLine(line2);

}

void ofApp::draw(){

	ofBackground(backgroundColor);
	ofSetColor(circlesColor);
	ofNoFill();
	drawLine(line1, ofGetWidth() / 10, ofGetHeight() * 2 / 5, 6);
	drawLine(line2, ofGetWidth() / 10, ofGetHeight() * 3 / 5, 8);

}

//--------------------------------------------------------------
// Methods

vector<CircleGrid> ofApp::circleGridsFromText(string text) {
	vector<CircleGrid> circleGrids;
	for (int i = 0; i < text.length(); i++) {
		for (int j = 0; j < font.chars.size(); j++) {
			if (font.chars[j].code == text[i]) {
				CircleGrid temp;
				float size = ofGetWidth() * 0.8;
				float scaleFactor = 1.66;
				temp.setup(6, 10, size / text.length() * scaleFactor, size / text.length() * scaleFactor);
				temp.applyMask(font.chars[j].character);
				circleGrids.push_back(temp);
			}
		}
	}
	return circleGrids;
}

void ofApp::updateLine(vector<CircleGrid>& line) {
	for (int i = 0; i < line.size(); i++) {
		line[i].update();
		line[i].scaleCircles(0.8);
	}
}

void ofApp::drawLine(vector<CircleGrid>& line, float x, float y) {
	drawLine(line, x, y, 1);
}

void ofApp::drawLine(vector<CircleGrid>& line, float x, float y, int iterations) {
	float xOffset = 0;
	for (int i = 0; i < line.size(); i++) {
		if (i > 0) {
			xOffset += line[i - 1].width * 0.6;
		}
		line[i].draw(x + xOffset, y, iterations);
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
