#include <iostream>


using namespace std;

int main(){

    //We use a const because we don't want this value changed.
    const double CALORIES_BURNED = 3.6;

    //A quick for loop will finish this program, it will iterate by 5's and output the calories and time.
    for(double i = 0; i < 31; i+=5){
        double result = i*CALORIES_BURNED;
        cout << "At " << i << " minutes you would have burned: " << result << " calories." << endl;
    }


    return 0;
}