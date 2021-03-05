#include "math.hpp"


int math::factorial(int n)
{
	unsigned long long factorial = 1;
	if (n < 0) {
		return 0;
	}
	else {
		for (int i = 1; i <= n; ++i) {
			factorial *= i;
			//based on basic math definition of factorial
		}
		return factorial;
	}
}

float math::simulatedw(Priority& p)
{
	float simw = (p.gettotalwait() + p.getservice()) / p.getn();
	return simw;
}

float math::simulatedwq(Priority& p)
{
	float simwp = (p.gettotalwait()) / p.getn();
	return simwp;
}

float math::simulatedidle(Priority& p)
{
	return p.getidle() / p.gettotal();
}

float math::simulatedrho(Priority& p)
{
	return p.getservice() / (p.getm() * p.gettotal());
}

float math::analyiticalidle(Priority& p)
{
	float s = 0;
	float result=0;
	int M = p.getm();
	int l = p.getlambda();
	int u = p.getmu();
	for (int i = 0; i < M; i++) {
		s = s + ((1 / factorial(i)) * (pow((static_cast<double>(l) / u), i)));
	}
	//sum is calculated seperate from the other two components to simplify testing each component
	float res1=((1 /static_cast<double>(factorial(M))))*(pow((static_cast<double>(l) / u), M));
	float res2 = (M * u) / static_cast<double>((M * u) - l);
	result= 1/(s+(res1*res2));
	return result;
}

float math::averagenumber(Priority& p)
{
	int l = p.getlambda();
	int u=p.getmu();
	int M = p.getm();
	float p0 = analyiticalidle(p);
	double div = static_cast<double>(l) / u;
	//similarly, the problem is broken down to find L
	double x = l * u * pow(div,M);
	double y = x / (factorial(M - 1) * pow(static_cast<double>((M * u) - l), 2));
	return (y * p0) + div;
}

float math::analyticalw(Priority& p)
{
	return averagenumber(p)/p.getlambda();
}

float math::analyticallq(Priority& p)
{
	return averagenumber(p)-(static_cast<double>(p.getlambda())/p.getmu());
}

float math::analyticalwq(Priority& p)
{
	return analyticallq(p)/static_cast<double>(p.getlambda());
}

float math::analyticalrho(Priority& p)
{
	return static_cast<float>(p.getlambda())/static_cast<float>(p.getm()*p.getmu());
}
