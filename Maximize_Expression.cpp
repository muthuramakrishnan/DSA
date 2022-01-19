#include<iostream>

using namespace std;

int main() {
	int n;
	long long p, q, r;
	cin >> n >> p >> q >> r;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//given condition i<=j<=k
	long long prefixMax[n], suffixMax[n];
	prefixMax[0] = p * arr[0];
	suffixMax[n - 1] = r * arr[n - 1];

	for (int i = 1; i < n; i++) {
		prefixMax[i] = max(prefixMax[i - 1], p * arr[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		suffixMax[i] = max(suffixMax[i + 1], r * arr[i]);
	}

	long long maxVal = INT64_MIN;
	for (int i = 0; i < n; i++) {
		maxVal = max(prefixMax[i] + q * arr[i] + suffixMax[i], maxVal);
	}
	cout << maxVal;

}
