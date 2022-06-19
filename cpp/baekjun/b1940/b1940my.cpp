// 1. 1 try test는 통과하는데 안풀림.
// 2. 중복허용인지 모름 고유번호라길래 고유한줄
#include <bits/stdc++.h>
using namespace std;
int n,k,ret;
map<int,int> _map;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		_map[temp]++;
	}

	for(auto v: _map){
		if (v.second == 0) continue;
		if (k <= v.first) continue;
		int target = k - v.first;
		while(_map[v.first] > 0){
			if(_map[target]) {
				_map[target] = _map[target]-1;
				_map[v.first]--;
				cout << v.second << endl;
				cout << _map[target] << endl;
				if(_map[v.first] >=0 ) ret++;
			}
			if(_map[target] == 0) break;
		}
	}

	cout << ret << "\n";
	return 0;
}
