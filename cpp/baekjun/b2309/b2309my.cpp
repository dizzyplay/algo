// https://www.acmicpc.net/problem/2309
#include <bits/stdc++.h>
using namespace std;

int arr[9]= {20,7,23,19,10,15,25,8,13};
int arrs = 9;

vector<int> v;
int m = 7;
bool combination(int n) {
	if (v.size() == m) {
		vector<int> rr;
		for(auto x: v) {
			cout << x << " ";
			rr.push_back(arr[x]);
		}
		cout << "----" << endl;
		if(100 == accumulate(rr.begin(), rr.end(), 0)) {
			sort(rr.begin(), rr.end());
			for(auto x: rr) {
				cout << x << endl;
			}
			return 1;
		}
		return 0;
	}
	for(int i =n; i<arrs; i++) {
		v.push_back(i);
		bool f = combination(i+1);
		if (f) return 1;
		v.pop_back();
	}
	return false;

}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	combination(0);
	return 0;
}
