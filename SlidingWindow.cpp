#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	//calculate the sum of the first window
	int sum=0;
	for(int i=0; i<k; i++){
		sum += arr[i];
	}
	for(int i=k; i<n; i++){
		//print the answer for previous window
		cout<<sum<<" ";
		sum += arr[i];
		sum -= arr[i-k];
	}
	cout<<sum;
}
