//find out the sum of all possible sub arrays

#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//brute force will take o(n2) time
	//let's take a reverse approach.
	//find out in how many sub arrays each element can occur
	//it can have i+1 starting points & n-1 ending points
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] * (i + 1) * (n - 1);
	}

	cout << sum;
}
