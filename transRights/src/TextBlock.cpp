#include "TextBlock.h"

//--------------------------------------------------------------
void TextBlock::setup(int width, int height, DisplayFunction display) {
	this->width = width;
	this->height = height;
	this->display = display;

	x = 0;
	y = 0;
	xMin = 0;
	xMax = ofGetWidth();
	yMin = 0;
	yMax = ofGetHeight();
	weight = ofGetWidth() > ofGetHeight() ? ofGetWidth() / 100 : ofGetHeight() / 100;
}

void TextBlock::update(ofVec2f unscaledPosition) {
	x = ofMap(unscaledPosition.x, 0, 1, xMin, xMax);
	y = ofMap(unscaledPosition.y, 0, 1, yMin, yMax);
}

void TextBlock::draw() {
	display(x - (width / 2), y - (height / 2), width, height, weight);
}

void TextBlock::setBounds(int xMin, int xMax, int yMin, int yMax) {
	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
}