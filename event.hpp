#pragma once
using namespace std;
class Event
{
public:
	bool type;
	//type 0 signifies arrival, 1 signifies departure
	float data;
	Event(bool newtype, float newdata);
	//comparators used to drive STL priority queue behavior
	friend bool operator < (const Event& lhs, const Event& rhs);
	friend bool operator > (const Event& lhs, const Event& rhs);
};

