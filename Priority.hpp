#pragma once
#include "customer.hpp"
#include "event.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
using namespace std;
class Priority
{
private:
	int mu;
	int lambda;
	int M;
	queue<customer> FIFO;
	int serverAvailableCount;
	int customerWaitedCnt = 0;
	float totalWaitTime = 0;
	float serviceTime = 0;
	float idleTime = 0;
	float currentWaitTime = 0;
	float totaltime = 0;
	//statistics drivers
	int n;
	public:
	Priority();
	float getNextRandomInterval(int avg);
	customer inputcus;
	//used to call up the customer being manipulated in a function
	vector<customer> inputvec;
	//used to store all customers in the system
	priority_queue < Event, vector<Event>, greater<Event> >pq;
	void processStatistics();
	void processNextEvent();
	//all other functions are accessors to drive math functions in a seperate class
	float gettotal();
	float getidle();
	float gettotalwait();
	float getservice();
	float getn();
	float getm();
	int getlambda();
	int getmu();
	double getwaited();
	
};

