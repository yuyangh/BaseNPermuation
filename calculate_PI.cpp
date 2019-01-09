/*
Programming Language: C++
Compilation Environment: C++11
*/


#include <iostream>
#include <math.h>
#include <set>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

long double calculate_PI(unsigned long steps){
	double prev=0;
	long double area=0;
	long double step=1.0/steps;
	for (double x = -1; x < 1; x+=step) {
		long double y=sqrt(1-pow(x,2));
		area+=(y+prev)*step;
	}
	return 2.0*area;
}

int main() {
	auto pi=calculate_PI(10000000);
	cout<<fixed<<setprecision(20)<<"Result: "<<pi<<endl;
	// Result: 3.14159265415426325633
	return 0;
}