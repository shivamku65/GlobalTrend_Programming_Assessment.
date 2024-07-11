//Maximum difference between any two elements in array
#include <bits/stdc++.h>
using namespace std;

int maximumDiff(int arr[], int n)
{
	sort(arr,arr+n);
	return arr[n-1]-arr[0];
}

int main()
{
	int arr[] = { 1,5,2,6,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maximumDiff(arr, n);

	return 0;
}
