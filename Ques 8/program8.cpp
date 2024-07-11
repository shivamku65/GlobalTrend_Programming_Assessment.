// To find GCD of two numbers\

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int res = min(a, b);
    while (res > 0) {
        if (a % res == 0 && b % res == 0) {
            break;
        }
        res--;
    }
    return res;
}

int main()
{
    int a = 10, b = 5;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}

