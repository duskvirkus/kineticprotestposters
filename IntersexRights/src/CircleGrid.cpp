#include "CircleGrid.h"

void CircleGrid::setup(int columns, int rows, float width, float height) {
	columns % 2 == 0 ? this->columns = columns + 1 : this->columns = columns;
	rows    % 2 == 0 ? this->rows    = rows    + 1 : this->rows    = rows;
	this->width  = width;
	this->height = height;
	for (int i = 0; i < (this->columns + 2) * (this->rows + 2); i++) {
		circles.push_back(CircleData());
		mask.push_back(true);
	}

	maskOn = true;
	for (int i = 0; i < this->columns + 2; i++) {
		mask[i] = false;
		mask[index(i, this->rows + 1, this->columns + 2)] = false;
		if (rows % 2 == 0) mask[index(i, this->rows, this->columns + 2)] = false;
	}
	for (int i = 0; i < this->rows + 2; i++) {
		mask[index(0, i, this->columns + 2)] = false;
		mask[index(this->columns + 1, i, this->columns + 2)] = false;
		if (rows % 2 == 0) mask[index(this->columns, i, this->columns + 2)] = false;
	}

	noiseScale = 1;
	movementScale = 1.2;
	radiusScale = 1.2;
}

void CircleGrid::applyMask(ofImage maskImage) {
	maskImage.draw(0, 0, 100, 100);
	for (int i = 0; i < maskImage.getWidth() && i < columns + 1; i++) {
		for (int j = 0; j < maskImage.getHeight() && j < rows + 1; j++) {
			mask[index(i + 1, j + 1, columns + 2)] = maskImage.getColor(i, j).getBrightness() < 127;
		}
	}
}

void CircleGrid::update() {
	float scale = width > height ? width / columns : height / rows;
	float maxSize = sqrt(scale / 2 * scale / 2 + scale / 2 * scale / 2);
	for (int i = 0; i < columns + 2; i++) {
		for (int j = 0; j < rows + 2; j++) {
			if (index(i, j, (columns + 2)) % 2 == 0) {
				circles[index(i, j, (columns + 2))] = CircleData(
					((i - 1) * scale) + ofMap(
						ofNoise(
							sin((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							cos((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							i + j + 1), 
						0, 1, 0, maxSize * movementScale
					),
					((j - 1) * scale) + ofMap(
						ofNoise(
							sin((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							cos((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							i + j - 1),
						0, 1, 0, maxSize * movementScale
					),
					ofMap(
						ofNoise(
							sin((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							cos((ofGetFrameNum() / static_cast<float>(NUMBER_OF_FRAMES)) * PI) * noiseScale,
							i + j),
						0, 1, maxSize / 2, maxSize * radiusScale
					)
				);
			}
		}
	}
	for (int i = 1; i < columns + 1; i++) {
		for (int j = 1; j < rows + 1; j++) {
			if (index(i, j, columns + 2) % 2 == 1) {
				int above = index(i - 1, j    , columns + 2);
				int below = index(i + 1, j    , columns + 2);
				int left  = index(i    , j - 1, columns + 2);
				int right = index(i    , j + 1, columns + 2);
				float calcX = ofLerp(
					circles[above].x + circles[above].radius,
					circles[below].x - circles[below].radius,
					0.5
				);
				float calcY = ofLerp(
					circles[left].y + circles[left].radius,
					circles[right].y - circles[right].radius,
					0.5
				);
				float calcRadius1 = (
					ofDist(
						circles[above].x,
						circles[above].y,
						circles[below].x,
						circles[below].y
					) - (
						circles[above].radius +
						circles[below].radius
						)
					) / 2;
				float calcRadius2 = (
					ofDist(
						circles[left].x,
						circles[left].y,
						circles[right].x,
						circles[right].y
					) - (
						circles[left].radius +
						circles[right].radius
						)
					) / 2;
				circles[index(i, j, columns + 2)] = CircleData(
					calcX,
					calcY,
					(calcRadius1 < calcRadius2 ? calcRadius1 : calcRadius2)
				);
			}
		}
	}
}

void CircleGrid::scaleCircles(float scale) {
	for (int i = 0; i < circles.size(); i++) {
		circles[i].radius *= scale;
	}
}

void CircleGrid::draw(float x, float y) {
	draw(x, y, 1);
}

void CircleGrid::draw(float x, float y, int interations) {
	for (int i = 0; i < circles.size(); i++) {
		if (!maskOn || mask[i]) {
			for (int j = 0; j < interations; j++) {
				ofDrawCircle(circles[i].x + x, circles[i].y + y, circles[i].radius - (j * 0.5));
			}
		}
	}
}

inline int CircleGrid::index(int x, int y, int w) {
	return x + y * w;
}

string CircleGrid::toString() {
	string s = "CircleGrid: w: " + to_string(width) + " h: " + to_string(height) + "\n";
	for (int i = 0; i < circles.size(); i++) {
		s += "  " + to_string(i) + circles[i].toString() + "\n";
	}
	return s;
}

ostream& operator<<(ostream& os, CircleGrid cg) {
	os << cg.toString();
	return os;
}
