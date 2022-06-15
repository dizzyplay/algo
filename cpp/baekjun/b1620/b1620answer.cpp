// 240ms
#include <bits/stdc++.h>

using namespace std;

map <int, string> _m1;
map <string, int> _m2;
int n,k;
string s;
int main(){
	cin >> n >> k;

	for(int i=1; i<=n; i++){
		cin >> s;
		_m1.insert({i, s});
		_m2.insert({s, i});
	}

	for(int i=0; i<k; i++){
		cin >> s;
		if (atoi(s.c_str()) == 0) {
			cout << _m2.find(s) -> second << "\n";
		}else {
			cout << _m1.find(atoi(s.c_str())) -> second << "\n";
		}
	}
	return 0;
}
