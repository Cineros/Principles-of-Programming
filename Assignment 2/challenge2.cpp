//We need iostream again here to recieve inputs.
#include <iostream>
//We are working with strings and as such need to include the library for them.
#include <string>


using namespace std;

int main(){

    //Initialize needed vars here.
    string month_1_name = "";
    string month_2_name = "";
    string month_3_name = "";
    double month_1_rain = 0;
    double month_2_rain = 0;
    double month_3_rain = 0;


    //This isnt the best way to do this. However, it causes less confusion for the user.
    cout << "Please input the names of the threes months that you would like to calculate the rainfall for: " << endl;
    cin >> month_1_name;
    cin >> month_2_name;
    cin >> month_3_name;
    cout << "Please input the rainfall for each month in sequential order." << endl;
    cin >> month_1_rain;
    cin >> month_2_rain;
    cin >> month_3_rain;

    /*
    While we could do input validation it is probably not needed in this case.
    We also could set the precision of the output but I also feel as that is not needed here.
    */
   
    //We output our result here.
    cout << "The average rainfall for " << month_1_name << 
    ", " << month_2_name << ", and " << month_3_name << " was " <<
    ((month_1_rain+month_2_rain+month_3_rain)/3) << " inches." << endl;

    return 0;
}