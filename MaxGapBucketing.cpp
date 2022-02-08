#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	int minNo = INT_MAX;
	int maxNo = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		//find out what is the min & max elements
		minNo = min(minNo, arr[i]);
		maxNo = max(maxNo, arr[i]);
	}

	if (minNo == maxNo || n < 2)
		return 0;
	//find out min possible max consecutive difference
	int gap = (maxNo - minNo) / (n - 1);
	if ((maxNo - minNo) % (n - 1) != 0) {
		gap++;
	}

	//create buckets to store min & max of each bucket
	int minBucketValue[n], maxBucketValue[n];

	for (int i = 0; i < n; i++) {
		minBucketValue[i] = INT_MAX;
		maxBucketValue[i] = INT_MIN;
	}
	for (int i = 0; i < n; i++) {
		//find out in which bucket the current term should go into
		int bucket = (arr[i] - minNo) / gap;

		//for example max=60, min=10, N=6 --> 60-10 / 5 --> 10
		//min possible ans = 10.  so each bucket is of size 10
		minBucketValue[bucket] = min(minBucketValue[bucket], arr[i]);
		maxBucketValue[bucket] = max(maxBucketValue[bucket], arr[i]);

	}

	//we have found out the min & max value for each buckets
	//Next step minValue[bucket] - maxValue[bucket-1]

	int ans = INT_MIN;
	int prevMax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (minBucketValue[i] == INT_MAX)
			continue;
		if (prevMax == INT_MIN)
			prevMax = maxBucketValue[i];
		else {
			ans = max(ans, minBucketValue[i] - prevMax);
			prevMax = maxBucketValue[i];
		}
	}

	cout << ans;

}
