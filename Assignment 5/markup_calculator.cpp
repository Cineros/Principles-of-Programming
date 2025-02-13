#include <iostream>
#include <iomanip>


using namespace std;


/* Here we have a function that takes two floats as input and in one line
returns the retail price of the item.
*/
float calculateRetailPrice(float price, float markup){
    return (price + price*(markup*.01));
}

int main(){
    //Initialize the two inputs that we need.
    float price = 0;
    float markup = 0;

    /*These while loops could be dangerous as if the user manages to break the input 
    they will cause the program to run forever. However, they function very well for 
    input validation. Perhaps a do/while loop would be more apt for this case.*/
    while(true){
        cout << "What is the initial price of the item?" << endl;
        cin >> price;
        if(price <= 0 || cin.fail()){
            cout << "Sorry that input is invalid! Please try again." << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }else{
            break;
        }
    }
    while(true){
        cout << "What is the markup percentage of the item?" << endl;
        cin >> markup;
        if(markup < 0 || cin.fail()){
            cout << "Sorry the input is invalid! Please try again. " << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }else{
            break;
        }
    }
    //Here we run the two inputs through our function with a setprecision and out put to console.
    cout << "The retail price is: " << fixed << setprecision(2) << calculateRetailPrice(price, markup) << endl;
    




    return 0;
}