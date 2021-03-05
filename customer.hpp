#pragma once
using namespace std;
class customer
{
public:
	float arrivalTime;
	float startofserviceTime;
	float departureTime;
	customer* nextcust;
	//nextcust is a deprecated pointer that would have been used for non-STL queues
	customer(float input);
	customer();
};

