//question
// 1 2 3   ===> 7 4 1
// 4 5 6		8 5 2
// 7 8 9		9 6 3

//first find a transpose of it
// 1 4 7 ==> then just do a reverse of each row
// 2 5 8
// 3 6 9

#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}

	//find the transpose of a matrix
	//swap(arr[i][j], arr[j][i])
	//but make sure this is done only to upper  / lower half

	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			//do it only for i greater than j
			//so change the condition in for loop
			swap(arr[i][j], arr[j][i]);
		}
	}

	//now reverse each row
	for(int i=0; i<n; i++){
		for(int j=0; j<n/2; j++){
			swap(arr[i][j], arr[i][n-(j+1)]);
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
