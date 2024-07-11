//Check if string contain only alphabets or not
#include <bits/stdc++.h>
using namespace std;

class Check{
public:
    bool onlyAlphabets(string str, int n){
        if(str.empty()){
            return false;
        }

        for(int i = 0; i < n; i++){
            if(!isalpha(str[i])){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string str = "Assessment";
    int length = str.length();
    Check c;

    cout << "Result " << c.onlyAlphabets(str, length)<< endl;
}