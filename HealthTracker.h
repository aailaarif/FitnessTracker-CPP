#pragma once
#include <string>
#include "HealthData.h"
#include <vector>
using namespace std;
class HealthTracker
{
private:
	string userName;
	string userGender;
	int userAge;
	int size;
	vector<HealthData> history;
	int counter;
public: 
	HealthTracker(string userName, string userGender, int userAge);
	~HealthTracker();
	void input();
	void printHistory();
	void printRecent();
	void printSummary();
	void menu();

};
