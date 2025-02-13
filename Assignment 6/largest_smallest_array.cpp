#include <iostream>


using namespace std;

//This function iterates over the array provided and checks for the lowest numeric value in the array.
int find_min(int array[], int size){
    int min = array[0];
    for(int i = 0; i < size; i++){
        if(min > array[i]){
            min = array[i];
        }
    }

    return min;
}
//This function iterates over the array and provides the largest numeric value.
int find_max(int array[], int size){
    int max = array[0];
    for(int i = 0; i < size; i++){
        if(max < array[i]){
            max = array[i];
        }
    }

    return max;
}

int main(){
    //Here we initialize the input array and the input variable.
    int input_array[10];
    int input = 0;


    //Here we ask for values to fill the array, with input validation.
    for(int i = 0; i < 10; i++){
        cout << "Please enter a numeric value. " << endl;
        cin >> input;
        if(cin.fail()){
            i--;
            cout << "sorry that is not a numeric value. Clearing input... please try again. " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }else{
            input_array[i] = input;
        }
    }

    /*While we should initialize all our varibles at the top of main, seperating this out can 
    make this easier to read. I could store the answers as two seperate variables but i've been using python recently and
    forgot I couldn't return two vars in the same function.
    */
    int min_max[2];

    //Due to the nature of C++ it is harder to return two variables from a function than to just run the function again.
    //Another option would be to sort the array then return the lowest index and greatest index.
    //However, good sorting algorithms perform poorly on small datasets.
    //That being said this is the same O(n) as insertion sort as it is O(n^2).
    min_max[0] = find_min(input_array, 10);
    min_max[1] = find_max(input_array, 10);

    //Output the result and return 0 to end the program.
    cout << "The minimum value in the array is: " << min_max[0] << " The maximum value in the array is: " << min_max[1] << endl;

    return 0;

}