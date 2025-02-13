//We need iostream to output to the console and accept inputs here.
#include <iostream>

//Use the standard namespace since we have no conflicts and can reduce some amount of typing.
using namespace std;

int main(){

    //We need to initialize these variables to hold our inputs.
    int gallons = 0;
    int miles = 0;

    //We could put this into a loop if we needed to but asking once will be plenty.
    cout << "Welcome to the gas milage calculator" << endl;
    cout << "Please input the total number of gallons of gas your car can hold. " << endl;

    //Store our input as one of our free variables.
    cin >> gallons;
    cout << "How many miles can you drive on a full tank of gas? " << endl;

    //Store the next input as the other free variable.
    cin >> miles;

    //Output the result and end the program.
    cout << "Your car gets " << miles/gallons << " miles per gallon." << endl;

    return 0;
}