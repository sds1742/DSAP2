#include "Priority.hpp"
#include "customer.hpp"
#include "event.hpp"
#include "math.hpp"
#include <cmath>
using namespace std;
int main() {
	math m;
	Priority p;
	cout << "analytical value of Po=" << m.analyiticalidle(p) << ", simulated value of Po=" << m.simulatedidle(p) << endl;
	cout << "analytical value of L=" << m.averagenumber(p) << endl;
	cout << "analytical value of W=" << m.analyticalw(p) << ", simulated value of W=" << m.simulatedw(p) << endl;
	cout << "analytical value of Lq=" << m.analyticallq(p) << endl;
	cout << "analytical value of Wq= " << m.analyticalwq(p) << ", simulated value of Wq=" << m.simulatedwq(p) << endl;
	cout <<"analytical value of rho="<<m.analyticalrho(p) <<", simulated value of rho="<<m.simulatedrho(p)<<endl;
	return 0;
}