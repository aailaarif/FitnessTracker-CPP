#include "HealthData.h"
#include "HealthTracker.h"
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
HealthData::HealthData()
{
	weight = 0.0;
	exerciseType = "";
	exerciseTime = 0.0;
}
HealthData::HealthData(double weight, string exerciseType, double exerciseTime)
{
	this->weight = weight;
	this->exerciseType = exerciseType;
	this->exerciseTime = exerciseTime;
}
void HealthData::setWeight(double weight)
{
	this->weight = weight;
}
void HealthData::setExerciseType(string exerciseType)
{
	this->exerciseType = exerciseType;
}
void HealthData::setExerciseTime(double exerciseTime) 
{
	this->exerciseTime = exerciseTime;
}
double HealthData::getWeight() const
{
	return weight;
}
string HealthData::getExerciseType() const
{
	return exerciseType;
}
double HealthData::getExerciseTime() const
{
	return exerciseTime;
}
void HealthData::print() const
{
	cout << "Weight: " << weight << " kg" << endl;
	cout << "Exercise: " << exerciseType << " (" << exerciseTime << " minutes)" << endl;
}