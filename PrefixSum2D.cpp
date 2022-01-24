#include<iostream>
using namespace std;

int main() {
	int m, n;
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

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << prefixArray[i][j] << " ";
		}
		cout << endl;
	}
}
