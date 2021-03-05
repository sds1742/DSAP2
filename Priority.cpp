#include "Priority.hpp"
Priority::Priority()
{
	cout << "input the number of people in the system"<<endl;
	cin >> n;
	cout << "input the average number of arrivals in a time period" << endl;
	cin >> lambda;
	cout << "input the average number of people served in a time period" << endl;
	cin >> mu;
	cout << "input the number of servers" << endl;
	cin >> M;
	totalWaitTime = 0;
	if (M > 10) {
		cout << "wrong range";
		return;
	}
	else {
		serverAvailableCount = M;
		for (int i = 0; i < n; ++i) {
			float interval = getNextRandomInterval(lambda);
			float newarr = totaltime + interval;
			//keeps track of current time interval, used to generate customers and initialize total sim time
			inputvec.push_back(customer(newarr));
			totaltime = newarr;
		}
		for (int i = 0; i < 200; i++) {
			pq.push(Event(0, inputvec.at(i).arrivalTime));
			//inputs first set of arrivals
		}
		int itval = 200;
		//itval is used to add 200 items at a time whenver the size of pq is too low
		while (!pq.empty()) {
			processNextEvent();
			if ((pq.size() <= M + 1) && (itval < n)) {
				for (int i = itval; i < itval + 200; i++) {
					pq.push(Event(0, inputvec.at(i).arrivalTime));
				}
				itval = itval + 200;
			}
		}
	}
}

float Priority::getNextRandomInterval(int avg)
{
	float f = static_cast<float>(rand()/static_cast<float>(RAND_MAX));
	float intervalTime = -1*(1.0 / avg) * log(f);
	return intervalTime;
	//explain stack overflow
}

void Priority::processStatistics()
{
	currentWaitTime=(inputcus.startofserviceTime - inputcus.arrivalTime);
	//is 0 for non-FIFO items
	if (currentWaitTime>0) {
		customerWaitedCnt++;
	}
	totalWaitTime = totalWaitTime + currentWaitTime;
	serviceTime = serviceTime+(inputcus.departureTime - inputcus.startofserviceTime);
	if (serverAvailableCount == M) {
		if (!pq.empty()) {
			idleTime = idleTime + (pq.top().data-inputcus.departureTime);
		}
	}
}

void Priority::processNextEvent()
{
	if (pq.top().type == 0) {
		for (int i = 0; i < inputvec.size(); i++) {
			if (fabs(pq.top().data == inputvec.at(i).arrivalTime)) {
				inputcus = inputvec.at(i);
				//simple linear search to find the customer corresponding to the arrival
			}
		}
		
			if (!((serverAvailableCount <= 0)||(pq.size()>200))) {
				//the pq.size() call is used to supplement STL priority queue in terms of maintaining a size of at most 200
				serverAvailableCount = serverAvailableCount - 1;
				inputcus.startofserviceTime = inputcus.arrivalTime;
				float interval = getNextRandomInterval(mu);
				inputcus.departureTime = inputcus.arrivalTime + interval;
				pq.pop();
				pq.push(Event(1, inputcus.departureTime));
			}
			else {
				FIFO.push(inputcus);
				pq.pop();
			}
		}
	
	else {
		serverAvailableCount = serverAvailableCount + 1;
		if (!FIFO.empty()) {
			inputcus=FIFO.front();
			FIFO.pop();
			//initialize inputcus and remove it from fifo
			inputcus.startofserviceTime = pq.top().data;
			pq.pop();
			float interval = getNextRandomInterval(mu);
			inputcus.departureTime = inputcus.startofserviceTime + interval;
			
			pq.push(Event(1, inputcus.departureTime));
			serverAvailableCount = serverAvailableCount - 1;
			//produce departure event much like when pushing new customers into the system
		}
		else {
			pq.pop();
		}
		processStatistics();
	}
}


float Priority::gettotal()
{
	return totaltime;
}

float Priority::getidle()
{
	return idleTime;
}

float Priority::gettotalwait()
{
	return totalWaitTime;
}

float Priority::getservice()
{
	return serviceTime;
}

float Priority::getn()
{
	return n;
}

float Priority::getm()
{
	return M;
}

int Priority::getlambda()
{
	return lambda;
}

int Priority::getmu()
{
	return mu;
}

double Priority::getwaited()
{
	return customerWaitedCnt;
}






