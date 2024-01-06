//Aaila Arif
//Asks users for inputs such as name, gender, and age(validates age)
//presents option menu: option 1 inputs information such as weight(validates), exercise time(validates), and exercise type
//option 2 prints the information entered, or tells user that no information has been entered
//option 3 prints the history
//program keeps running until option 4 is entered, and the option entered by the user is validated
//Program has been refactored such that getting user info, showing the menu, getting user choice, inputting, and printing have
//been placed into functions
//Program has also been refactored to be able to store as many inputs as the user wants with a vector
#include <iostream>
#include <string>
#include "HealthTracker.h"
#include "HealthData.h"
using namespace std;

void getUserInfo(string& userName, string& userGender, int& userAge) {
    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "Enter your gender: ";
    getline(cin, userGender);

    cout << "Enter your age: ";
    cin >> userAge;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid data type! Input a valid age: ";
        cin >> userAge;
    }
}

int main() {

    string userName, userGender;
    int userAge;
    int size;

    getUserInfo(userName, userGender, userAge);
   
    HealthTracker health(userName, userGender, userAge);
    health.menu();

    return 0;
}
