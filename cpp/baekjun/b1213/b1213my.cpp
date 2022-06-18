#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	map<char,int> _map;

	cin >> s;

	for(auto c: s){
		_map[c]++;
	}

	char last;
	string ret="";
	for(auto v: _map){
		if (last) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
		if (v.second % 2 != 0){
			last = v.first;
		}else {
			for(int i=0; i<v.second / 2; i++){
				ret.push_back(v.first);
			}
		}
	}

	string result;
	cout << ret << endl;
	result.append(ret);
	reverse(ret.begin(), ret.end());
	result.push_back(last);
	result.append(ret);
	cout << result << "\n";

	return 0;
}
