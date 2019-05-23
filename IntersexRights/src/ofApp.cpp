#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks

void ofApp::setup(){
	backgroundColor = ofColor(255, 216, 0);
	circlesColor = ofColor(121, 2, 170);
}

void ofApp::update(){
	title();
}

void ofApp::draw(){
	ofBackground(backgroundColor);
	ofSetColor(circlesColor);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() / 4);
}

//--------------------------------------------------------------
// Inline Helpers

inline void ofApp::title() {
	stringstream titleStream;
	titleStream << PROJECT_NAME << " - " << CREATOR << " - FPS: " << static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());
}