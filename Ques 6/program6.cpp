//Find factorial of a number
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int number = 3;
    cout << "Factorial of " << number << "  is " << factorial(number) << endl;
    return 0;
}