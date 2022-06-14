#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr, r;

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		arr.push_back(t);
	}
	r.push_back(arr[0]);
	for(int i=1; i<arr.size(); i++){
		r.push_back(r[i-1] + arr[i]);
	}

	int max=r[k-1];

	for(int i=0; i<r.size() -k; i++){
		if(r[i+k] - r[i] > max) max = r[i+k] - r[i];
	}
	cout << max;
	return 0;
}
