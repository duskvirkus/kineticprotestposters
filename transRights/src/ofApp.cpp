#include "ofApp.h"

//--------------------------------------------------------------
// openFrameworks
void ofApp::setup() {
	// Initalize Global Variables
	framesInAnimation = 300;
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	setupColors();

	// Start Background
	fbo.begin();
	ofBackground(lerpColor(color1, color2, 0.5));
	fbo.end();

	// Transparent Background
	setColorsAlpha(8);
	ofSetBackgroundAuto(false);
}

void ofApp::update() {
	title();
}

void ofApp::draw() {
	fbo.begin();

	transparentBackground(lerpColor(color1, color2, ofMap(sin(animationProgress() * TWO_PI), -1, 1, 0, 1)));

	ofSetColor(255);
	blockTransRights(ofMap(sin(animationProgress() * TWO_PI * 2), -1, 1, ofGetWidth() / 2 - 100, ofGetWidth() / 2 + 100) - 300, ofMap(sin(animationProgress() * TWO_PI), -1, 1, 300, ofGetHeight() - 300) - 200, 600, 400, 20);

	fbo.end();
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
// Admin

inline void ofApp::title() {
	ofSetWindowTitle("TransRights - Fi Graham - FPS: " + ofToString(static_cast<int>(ofGetFrameRate())));
}

inline void ofApp::transparentBackground(ofColor color) {
	ofSetColor(color);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

inline float ofApp::animationProgress() {
	return (ofGetFrameNum() % framesInAnimation) / static_cast<float>(framesInAnimation);
}

//--------------------------------------------------------------
// Text

void ofApp::blockTransRights(ofVec2f position, ofVec2f dimensions, int weight) {
	blockTransRights(position.x, position.y, dimensions.x, dimensions.y, weight);
}

void ofApp::blockTransRights(int x, int y, int w, int h, int weight) {
	int letterWidth = w / 7;
	int letterSpacing = letterWidth / 4;
	int letterHeight = (h - letterSpacing) / 2;

	blockT(x + ((letterWidth + letterSpacing) * 0.5), y, letterWidth, letterHeight, weight);
	blockR(x + ((letterWidth + letterSpacing) * 1.5), y, letterWidth, letterHeight, weight);
	blockA(x + ((letterWidth + letterSpacing) * 2.5), y, letterWidth, letterHeight, weight);
	blockN(x + ((letterWidth + letterSpacing) * 3.5), y, letterWidth, letterHeight, weight);
	blockS(x + ((letterWidth + letterSpacing) * 4.5), y, letterWidth, letterHeight, weight);

	blockR(x + ((letterWidth + letterSpacing) * 0), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
	blockI(x + ((letterWidth + letterSpacing) * 1), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
	blockG(x + ((letterWidth + letterSpacing) * 2), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
	blockH(x + ((letterWidth + letterSpacing) * 3), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
	blockT(x + ((letterWidth + letterSpacing) * 4), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
	blockS(x + ((letterWidth + letterSpacing) * 5), y + letterHeight + letterSpacing, letterWidth, letterHeight, weight);
}

void ofApp::blockT(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w / 2 - (weight / 2), y, weight, h, weight / 2);
}

void ofApp::blockR(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h / 2, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - (weight / 2), w, weight, weight / 2);
	ofDrawRectRounded(x + (w * 3 / 4) - weight, y + (h / 2), weight, h / 2, weight / 2);
}

void ofApp::blockA(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - (weight / 2), w, weight, weight / 2);
}

void ofApp::blockN(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
}

void ofApp::blockS(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h / 2, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - weight, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y + (h / 2) - weight, weight, h / 2 + weight, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
}

void ofApp::blockI(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w / 2 - (weight / 2), y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
}

void ofApp::blockG(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y + (h / 2), weight, h / 2, weight / 2);

}

void ofApp::blockH(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y + (h / 2) - weight, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
}

//--------------------------------------------------------------
// Color

inline void ofApp::setupColors() {
	color1 = ofColor(91, 206, 250);
	color2 = ofColor(245, 169, 184);
}

inline void ofApp::setColorsAlpha(int a) {
	color1.a = a;
	color2.a = a;
}

inline ofColor ofApp::lerpColor(ofColor c1, ofColor c2, float amt) {
	ofColor c;
	c.r = ofLerp(c1.r, c2.r, amt);
	c.g = ofLerp(c1.g, c2.g, amt);
	c.b = ofLerp(c1.b, c2.b, amt);
	c.a = ofLerp(c1.a, c2.a, amt);
	return c;
}