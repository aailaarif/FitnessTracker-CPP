#include "HealthTracker.h"
#include "HealthData.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

HealthTracker::HealthTracker(string userName,
    string userGender, int userAge)
{
	this->userName = userName;
	this->userGender = userGender;
	this->userAge = userAge;
	counter = 0;
}
HealthTracker:: ~HealthTracker()
{
	cout << "Memory has been cleared.";
}
void HealthTracker::input()
{
    double weight;
    string exerciseType;
    double exerciseTime;
    if (counter == size) {
        for (int i = 0; i < size - 1; i++) {
            history[i] = history[i + 1];
        }
        counter = size - 1;
    }
    cout << "Enter weight in kg: ";
    cin >> weight;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid data type! Input a valid integer: ";
        cin >> weight;
    }
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Enter exercise type today: ";
    getline(cin, exerciseType);
    cout << "Enter exercise time: ";
    cin >> exerciseTime;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid data type! Input a valid integer: ";
        cin >> exerciseTime;
    }
    history.push_back(HealthData(weight, exerciseType, exerciseTime));

    counter++;
}
void HealthTracker::printHistory()
{
    if (!history.empty()) {
        cout << "Fitness History:" << endl;
        cout << userName << "(" << userGender << "," << userAge << ")" << endl;

        for (auto it = history.rbegin(); it != history.rend(); ++it) {
            const HealthData& data = *it;
            cout << "Weight: " << data.getWeight() << " kg" << endl;
            cout << "Exercise: " << data.getExerciseType() << " ("
                << data.getExerciseTime() << " minutes)" << endl;
        }
    }
    else {
        cout << "No fitness data to print." << endl;
    }
   
}
void HealthTracker::printRecent()
{
    if (!history.empty()) {
        cout << userName << "(" << userGender << "," << userAge << ")" << endl;
        const HealthData& recentData = history.back();
        cout << "Weight: " << recentData.getWeight() << " kg" << endl;
        cout << "Exercise: " << recentData.getExerciseType()
            << " (" << recentData.getExerciseTime() << " minutes)" << endl;
    }
    else {
        cout << "No fitness data to print." << endl;
    }
}
void HealthTracker::menu()
{
    int option = 0;
    while (option != 4) {

        cout << "\nOption 1: Input" << endl << "Option 2: Print" << endl 
            << "Option 3: Print History" << endl << "Option 4: Summary" << endl << "Option 5: Exit" << endl;
        cout << "Pick an option: " << endl;

        while (true) {
            cin >> option;
            if (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Option input is invalid. Pick an option: ";
            }
            else {
                break;
            }
        }

        if (option == 1) {
            input();
        }
        else if (option == 2) {
            printRecent();
        }
        else if (option == 3) {
            printHistory();
        }
        else if (option == 4){
            printSummary();
        }
        else {
            break;
        }
        option = 0;
    }
}

void HealthTracker::printSummary() {
    if (!history.empty()) 
    {
        double totalWeight = 0;
        double totalExerciseTime = 0;
        double highestWeight = history[0].getWeight();
        double lowestWeight = history[0].getWeight();
        double highestExerciseTime = history[0].getExerciseTime();
        double lowestExerciseTime = history[0].getExerciseTime();

        for (const HealthData& data : history) 
        {
            totalWeight += data.getWeight();
            totalExerciseTime += data.getExerciseTime();

            highestWeight = max(highestWeight, data.getWeight());
            lowestWeight = min(lowestWeight, data.getWeight());

            highestExerciseTime = max(highestExerciseTime, data.getExerciseTime());
            lowestExerciseTime = min(lowestExerciseTime, data.getExerciseTime());
        }

        double averageWeight = totalWeight / history.size();
        double averageExerciseTime = totalExerciseTime / history.size();

        cout << "Summary of Health Data:" << endl;
        cout << "Highest Weight: " << highestWeight << " kg" << endl;
        cout << "Lowest Weight: " << lowestWeight << " kg" << endl;
        cout << "Average Weight: " << averageWeight << " kg" << endl;
        cout << "Highest Exercise Time: " << highestExerciseTime << " minutes" << endl;
        cout << "Lowest Exercise Time: " << lowestExerciseTime << " minutes" << endl;
        cout << "Average Exercise Time: " << averageExerciseTime << " minutes" << endl;
    }
    else {
        cout << "No fitness data to calculate summary." << endl;
    }
}