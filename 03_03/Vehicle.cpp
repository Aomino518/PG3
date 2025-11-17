#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(const char* name) : name_(name)
{
	cout << name_ << "を製造" << endl;
}

Vehicle::~Vehicle()
{
	cout << name_ << "を解体" << endl;
}

void Vehicle::Move()
{
}
