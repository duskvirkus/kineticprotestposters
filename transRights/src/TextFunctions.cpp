#include "TextFunctions.h"

//--------------------------------------------------------------
// Text

void blockTransRights(int x, int y, int w, int h, int weight) {
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

void blockT(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w / 2 - (weight / 2), y, weight, h, weight / 2);
}

void blockR(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, (h + weight) / 2, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - (weight / 2), w, weight, weight / 2);
	ofDrawRectRounded(x + (w * 3 / 4) - weight, y + (h / 2), weight, h / 2, weight / 2);
}

void blockA(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - (weight / 2), w, weight, weight / 2);
}

void blockN(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
}

void blockS(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h / 2, weight / 2);
	ofDrawRectRounded(x, y + (h / 2) - weight, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y + (h / 2) - weight, weight, h / 2 + weight, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
}

void blockI(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x + w / 2 - (weight / 2), y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
}

void blockG(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x, y + h - weight, w, weight, weight / 2);
	ofDrawRectRounded(x + w - weight, y + (h / 2), weight, h / 2, weight / 2);

}

void blockH(int x, int y, int w, int h, int weight) {
	ofDrawRectRounded(x, y + (h / 2) - weight, w, weight, weight / 2);
	ofDrawRectRounded(x, y, weight, h, weight / 2);
	ofDrawRectRounded(x + w - weight, y, weight, h, weight / 2);
}
