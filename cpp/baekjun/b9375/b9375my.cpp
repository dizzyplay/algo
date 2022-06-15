// 원래의 조합수에 아무것도 선택하지않은 경우를 추가후 아무것도 선택하지 않은 조합만 뻄
// 2 , 1이라면 3 * 2 -1 = 5
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
