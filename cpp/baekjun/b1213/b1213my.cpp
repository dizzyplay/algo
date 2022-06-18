#include <bits/stdc++.h>
using namespace std;
int cnt[200];
string s,ret;
int main(){

	cin >> s;

	for(auto c: s){
		cnt[(int)c]++;
	}

	char mid;

	for(int i='Z'; i>='A'; i--){
		if (cnt[i]) {
			if(cnt[i] & 1) {
				if (mid) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				mid = (char)i;
				cnt[i]--;
			}
			for(int j=0; j<cnt[i] /2; j++){
				ret = (char)i+ ret;
				ret += (char)i;
			}
		}
	}

	if (mid){
		cout << mid << endl;
		ret.insert(ret.size()/2 , 1, mid);
	}
	cout << ret << endl;

	return 0;
}
