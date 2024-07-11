// To find the length of the longest substring without repeating characters
#include <bits/stdc++.h>
using namespace std;

bool areDifferent(string str, int i, int j)
{
    vector<bool> visited(256);

    for (int k = i; k <= j; k++) {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
    return true;
}

int longestUniqueSubstring(string str)
{
    int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDifferent(str, i, j))
                res = max(res, j - i + 1);
    return res;
}

int main()
{
    string str = "assessment";
    cout << "Input string is " << str << endl;
    int len = longestUniqueSubstring(str);
    cout << "Length of the longest non-repeating character substring is " << len;
    return 0;
}

