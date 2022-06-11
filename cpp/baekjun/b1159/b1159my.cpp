#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int c;
string s;
int main(){
	cin >> c;
	for(int i=0; i<c; i++){
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	for(int i=0; i<26; i++){
		if (cnt[i] >= 5) cout << (char)('a'+i);
	}
	return 0;
}
