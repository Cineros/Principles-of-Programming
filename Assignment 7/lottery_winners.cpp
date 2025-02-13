#include <iostream>

using namespace std;


//We use linear search here due to the array being rather small. 
int linear_search(int array[10], int target_number){
    int found_at = -1; //Initialize the array to -1 since 0 is a valid position in an array.
    //Perform Linear Search here
    for(int i = 0; i < 10; i++){
        if(array[i] == target_number){
            found_at = i;
        }
    }
    //Always return something with -1 as our base case.
    return found_at;
}


//I use this to adjust the suffix for the number. It's purely for readable output.
string get_suffix(int result){
    if(result == 0){
        return "st";
    }else if(result == 1){
        return "nd";
    }else if(result == 2){
        return "rd";
    }else{
        return "th";
    }
}



int main(){
    //Initialize vars here, we will need 12 total but one is an array of 10 numbers.
    int lucky_numbers[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 94222, 85647, 93121};
    int input = 0;
    int result = -1;

    //Common input validation here, realistically I should come up with a pure function to replace this loop.
    while(true){
        cout << "Please enter the lottery numbers for the week. " << endl;
        cin >> input;
        if(cin.fail()){
            cout << "Sorry that was not a valid number. " << endl;
            cout << "Clearing input please try again. " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }else{
            break;
        }
    }
    //re-set result to what returns from our linear_search. -1 will be our most common so it will return that on fail.
    result = linear_search(lucky_numbers, input);

    //A simple if/else to confirm our result and output to user.
    if (result != -1){
        //result+1 will return the result in a non-zero indexed form, which is easier to read.
        cout << "Winner! The number: " << lucky_numbers[result] << " was your " << result+1 << get_suffix(result) << " ticket!" << endl;

    }else{
        cout << "Nothing this week! Better luck next time!" << endl;
    }

    //return 0 when the program ends.
    return 0;
}