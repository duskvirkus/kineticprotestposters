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
	drawLine(line1, ofGetMouseX(), ofGetMouseY());
	drawLine(line2, 300, 300);

}

//--------------------------------------------------------------
// Methods

vector<CircleGrid> ofApp::circleGridsFromText(string text) {
	vector<CircleGrid> circleGrids;
	for (int i = 0; i < text.length(); i++) {
		for (int j = 0; j < font.chars.size(); j++) {
			if (font.chars[j].code == text[i]) {
				CircleGrid temp;
				temp.setup(6, 10, 200, 200);
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
		line[i].scaleCircles(0.75);
	}
}

void ofApp::drawLine(vector<CircleGrid>& line, float x, float y) {
	float xOffset = 0;
	for (int i = 0; i < line.size(); i++) {
		if (i > 0) {
			xOffset += line[i - 1].width * 0.6;
		}
		line[i].draw(x + xOffset, y);
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
