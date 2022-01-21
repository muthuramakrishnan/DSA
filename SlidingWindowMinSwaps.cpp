//given an array of size n & k
//find out the min number of swaps required to bring the elements which are less than or equal to k together

#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[n], legalElementsCount = 0;

	//count the number of elements that are less than or equal to k
	//if we count the number of legalElements, then we can inspect each sub arrays of that size
	//so that the answer can be found out based on the -> subarray which has max number of legalElements
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= k) {
			legalElementsCount++;
		}
	}

	//now the window size is legalElemnentsCount
	int maxContiguousLegalElements = INT_MIN;
	int count = 0;
	for (int i = 0; i < legalElementsCount; i++) {
		if (arr[i] <= k) {
			count++;
		}
	}

	for (int i = legalElementsCount; i < n; i++) {
		//update the answer
		maxContiguousLegalElements = max(maxContiguousLegalElements, count);

		if (arr[i] <= k) {
			count++;
		}
		if (arr[i - legalElementsCount] <= k) {
			count--;
		}
	}
	maxContiguousLegalElements = max(maxContiguousLegalElements, count);
	cout << legalElementsCount - maxContiguousLegalElements;
}
