#include "CircleData.h"

CircleData::CircleData() :
	x(0),
	y(0),
	radius(0)
{

}

CircleData::CircleData(float x, float y, float radius) :
	x(x),
	y(y),
	radius(radius)
{

}

string CircleData::toString() {
	return "[" + to_string(x) + ", " + to_string(y) + ", " + to_string(radius) + "]";
}

ostream& operator<<(ostream& os, CircleData cd) {
	os << cd.toString();
	return os;
}