#include "event.hpp"

Event::Event(bool newtype, float newdata)
{
	this->type = newtype;
	this->data = newdata;
}

bool operator<(const Event& lhs, const Event& rhs)
{
	return lhs.data<rhs.data;
}

bool operator>(const Event& lhs, const Event& rhs)
{
	return lhs.data>rhs.data;
}
