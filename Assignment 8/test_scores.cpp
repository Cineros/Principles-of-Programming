#include <iostream>


using namespace std;

string get_suffix(int result){
    if(result > 20){
        result = result % 10;
    }
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

void merge(float array[], int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new float[subArrayOne],
         *rightArray = new float[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void merge_sort(float array[], int const begin, int const end){
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

float calc_average(float arr[], int length){
    float average = 0;
    for(int i = 0; i < length; i++){
        average += arr[i];
    }
    return average/length;
}

float calc_average_drop_lowest(float arr[], int length){
    float average = 0;
    float min = 9999;
    for(int i = 0; i < length; i++){
        if(arr[i] < min){
            if(min != 9999){
                average += min;
            }
            min = arr[i];
        }else{
            average += arr[i];
        }
    }
    return average/(length-1);
}

int main(){
    int num_scores = 0;
    float input = 0;
    
    while(true){
        cout << "How many test score do you have? " << endl;
        cin >> num_scores;
        if(cin.fail() || num_scores < 0){
            cout << "Sorry that is not a integer. Please try again. " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }else{
            break;
        }
    }

    float* test_scores = new float[num_scores];
    cin.clear();
    cin.ignore(80, '\n');

    for(int i = 0; i < num_scores; i++){
        while(true){
            cout << "Please enter the: " << i+1 << get_suffix(i) << " test score. " << endl;
            cin >> input;
            if(cin.fail() || input < 0 || input > 100){
                cout << "Sorry that is not a valid input. Please try again. " << endl;
                cin.clear();
                cin.ignore(80, '\n');
            }else{
                break;
            }
        }
        test_scores[i] = input;
        cin.clear();
        cin.ignore(80, '\n');
    }

    float average = calc_average(test_scores, num_scores);
    float average_drop_lowest = calc_average_drop_lowest(test_scores, num_scores);
    merge_sort(test_scores, 0, num_scores - 1);
    cout << endl;
    cout << "The average test score for ALL tests is: " << average << "." << endl;
    cout << endl;
    cout << "The average test score dropping the lowest score is: " << average_drop_lowest << "." << endl;
    for(int n = 0; n < num_scores; n++){
        cout << test_scores[n] << endl;
    }




    //Flower box in case I need to debug test scores.
    /*for(int n = 0; n < num_scores; n++){
        cout << test_scores[n] << endl;
    } */
    


    return 0;
}