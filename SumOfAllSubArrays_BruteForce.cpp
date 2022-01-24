//this is a very naive solution - with O(N^6) time complexity

#include<iostream>
using namespace std;

int getSum(int i1, int j1, int i2, int j2, int *arr, int m, int n ){
    int sum=0;
	for(int i=i1; i<=i2; i++){
	    for(int j=j1; j<=j2; j++){
	        sum += *((arr + i*n) + j);
	    }
	}
	return sum;
}
int main(){
	int m, n;
	cin>>m>>n;

	int arr[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}

	int ans = 0;
	for(int i1=0; i1<m; i1++){
		for(int j1=0; j1<n; j1++){
			for(int i2=i1; i2<m; i2++){
				for(int j2=j1; j2<n; j2++){
					ans += getSum(i1, j1, i2, j2, &arr[0][0], m, n);
				}
			}
		}
	}

	cout<<ans;
}
