#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> m;
		map<string,int> _map;
		for(int j=0; j<m; j++){
			string a,b;
			cin >> a >> b;
			_map[b]++;
		}
		int ret=1;
		for(auto v : _map) {
			ret *= v.second+1;
		}
		ret--;
		cout << ret << "\n";
	}
	return 0;
}
