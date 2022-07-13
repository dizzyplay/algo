#include <bits/stdc++.h>
using namespace std;

map<int, int> m,o;
vector<pair<int,int>> v;
int n,c;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return o[a.second] < o[b.second];
	}
	return a.first > b.first;
}

int main(){
	cin >> n >> c;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		m[a] += 1;
		if(o[a] == 0) o[a] = i+1;
	}
	for(auto vv : m) {
		v.push_back({vv.second, vv.first});
	}
	sort(v.begin(), v.end(),cmp);


	for(auto vv: v){
		for(int i=0; i<vv.first; i++){
			cout << vv.second << " ";
		}
	}

	return 0;
}
