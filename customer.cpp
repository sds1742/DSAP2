#include "customer.hpp"

customer::customer(float input)
{
	arrivalTime = input;
	departureTime = 0;
	startofserviceTime = 0;
	nextcust = nullptr;
}

customer::customer()
{
	arrivalTime = 0;
	departureTime = 0;
	startofserviceTime = 0;
	nextcust = nullptr;
}
