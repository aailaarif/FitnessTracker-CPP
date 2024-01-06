#pragma once
#include <string>
using namespace std;
class HealthData
{
private:
	double weight;
	string exerciseType;
	double exerciseTime;
public:
	HealthData();
	HealthData(double weight, string exerciseType, double exerciseTime);
	void setWeight(double weight);
	void setExerciseType(string exerciseType);
	void setExerciseTime(double exerciseTime);
	double getWeight() const;
	string getExerciseType() const;
	double getExerciseTime() const;
	void print() const;
	
};
 