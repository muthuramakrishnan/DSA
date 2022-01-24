#include<iostream>
using namespace std;

int main() {
	int m, n, q;
	cin >> m >> n;

	int arr[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int prefixArray[m][n];
	prefixArray[0][0] = arr[0][0];

	for (int i = 1; i < m; i++) {
		prefixArray[i][0] = prefixArray[i - 1][0] + arr[i][0];
	}
	for (int j = 1; j < n; j++) {
		prefixArray[0][j] = prefixArray[0][j - 1] + arr[0][j];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m; j++) {
			prefixArray[i][j] = prefixArray[i - 1][j] + prefixArray[i][j - 1]
					+ arr[i][j] + -prefixArray[i - 1][j - 1];
		}
	}

	cin>>q;

	while (q--) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;

		int ans = prefixArray[i2][j2];
		if (j1 > 0) {
			ans -= prefixArray[i2][j1 - 1];
		}
		if (i1 > 0) {
			ans -= prefixArray[i1 - 1][j2];
		}
		if(i1>0 && j1>0){
			ans += prefixArray[i1-1][j1-1];
		}

		cout << ans << endl;

	}
}
