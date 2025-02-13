#include <iostream>

using namespace std;

int main(){
    int input = 0;
    int sum = 0;


    //Here we take input and use a for loop to add all numbers up to that number.
    cout << "Please enter a positive integer: " << endl;
    cin >> input;
    for(int i = 0; i < input+1; i++){
        sum += i;
    }

    cout << sum << endl;

    return 0;
}