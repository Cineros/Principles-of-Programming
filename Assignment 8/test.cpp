#include <iostream>
#include <random>
#include <chrono>

using namespace std;

double IntsToDbl(int ipart, int decpart)
{
    //The decimal part:
    double dp = (double) decpart;
    while (dp > 1)
    {
        dp /= 10;
    }

    //Joint boths parts
    return ipart + dp;
}

int main(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator;

    generator.seed(seed);
    float num_scores = generator()%100;

    cout << num_scores << endl;

    for(int i = 0; i < num_scores; i++){
        seed+=i;
        generator.seed(seed);
        int first = generator()%100;
        int last = generator()%100;
        cout << IntsToDbl(first,last) << endl;
    }


    return 0;
}