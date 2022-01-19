#include<iostream>
using namespace std;

//n is the number of flowers
//m is the number of sub arrays suggessted by her mother
//p is the start index of one of the suggessted subbarrays
//q is the end index of one of the suggessted subarrays

int main() {
	int n, m;
	cin >> n >> m;

	int flowers[n];
	for (int i = 0; i < n; i++) {
		cin >> flowers[i];
	}

	int prefixSum[n];
	prefixSum[0] = flowers[0];
	for (int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i - 1] + flowers[i];
	}
	int max = 0;
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		if (l >= 0 && r >= 0) {
			int sum = prefixSum[r];
			if (l > 0) {
				sum -= prefixSum[l - 1];
			}
			if (sum > 0)
				max += sum;
		}
	}

	cout << max;
}
