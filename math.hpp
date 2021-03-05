#pragma once
#include "Priority.hpp"
#include "customer.hpp"
#include "event.hpp"
class math
{
private:
	int factorial(int n);
public:
	float simulatedw(Priority& p);
	float simulatedwq(Priority& p);
	float simulatedidle(Priority& p);
	float simulatedrho(Priority& p);
	float analyiticalidle(Priority& p);
	float averagenumber(Priority& p);
	float analyticalw(Priority& p);
	float analyticallq(Priority& p);
	float analyticalwq(Priority& p);
	float analyticalrho(Priority& p);
};

