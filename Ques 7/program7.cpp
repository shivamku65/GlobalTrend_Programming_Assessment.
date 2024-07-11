//To find sum of digits of number

#include <bits/stdc++.h>
using namespace std;

int main(){

    int num, s, sum =0;
    cout << "Enter a number"<<endl;
    cin >> num;
    while(num > 0){
        s = num % 10;
        sum = sum + s;
        num = num/10;
    }
    cout <<"Sum of a number is " << sum << endl;
    return 0;
}