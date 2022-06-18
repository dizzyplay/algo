#include <bits/stdc++.h>
using namespace std;
int cnt[130];
string s,ret;
char mid;
int main(){
	cin >> s;
	for(auto c: s){
		cnt[(int)c]++;
	}
	for(int i='Z'; i>='A'; i--){
		if (cnt[i]) {
			if(cnt[i] & 1) {
				if (mid) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				mid = (char)i;
			}
			for(int j=0; j<cnt[i] /2; j++){
				ret = (char)i+ ret;
				ret += (char)i;
			}
		}
	}

	if (mid){
		ret.insert(ret.size()/2 , 1, mid);
	}
	cout << ret << endl;

	return 0;
}
