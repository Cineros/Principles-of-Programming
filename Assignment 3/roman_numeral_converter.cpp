//We need the iostream library for input/output
#include <iostream>
#include <string>

//Here we include the limits library to assist in resetting cin.
#include <limits>

using namespace std;

/*Here we make a function outside of main to convert to roman numerals. 
This keeps the main function readable */
string convert_to_RN(int num){
    string answer = "";
    //This function is written to be expanded on if needed, as you can simply add other cases on top.
    while(num > 0){
        if (num >= 10){
            answer += 'X';
            num -= 10;
        //This if handles one of two unique cases, 9, as it is represented with 'IX' not 'VIIII'
        }else if ((num + 1) % 10 == 0){
            answer += "IX";
            num -= 9;
        //This handles our other special case, 4, which is represented with 'IV' not 'IIII'
        }else if ((num + 1) % 5 == 0){
            answer += "IV";
            num -= 4;
        }else if(num >= 5){
            answer += 'V';
            num -= 5;
        }else{
            for(int i = num; i > 0; i--){
                answer += 'I';
                num--;
            }
        }
    }
    
    return answer;
}

int main(){
    int input = 0;


    //We want to use a while loop for input vailidation as we want the program to have an output.
    while(true){
        //Here we use a try catch block to ensure that the input is an integer.
        try{
            cout << "Please input a number within the range of 1 to 10: " << endl;
            cin >> input;

            //We need to know if cin fails to write to our input integer. If it does it throws error 505.
            if (!cin.fail()){
                if (input > 10){
                    cout << "That number is greater than 10. Please input a number that is in the range of 1-10. " << endl;
                    input = 0;
                }else if (input < 1){
                    cout << "That number is less than 1. Please input a number in the range of 1-10." << endl;
                    input = 0;
                }else{
                    //If our input is valid and passes our checks we send it to the converter function to recieve our output.
                    cout << convert_to_RN(input);
                    //Then we break out of our generic while(true) loop.
                    break;
                }
            }else{
                //Here we throw our generic error code 505.
                throw 505;
            }
        } 
        //Here we catch a generic error, in this case 505 our input validation error.
        catch(...){
            cout << "Input is not an int... reseting input. Please try again. " << endl;
            //We need to call both clear and ignore to fully clean cin.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input = 0;
        }
    }



    return 0;
}