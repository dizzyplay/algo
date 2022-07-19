#include <bits/stdc++.h>
using namespace std;

string s;
bool flag;
int cnt[30], vcnt, lcnt;
int e = 'e' - 'a';
int o = 'o' - 'a';

string mo = "aiueo";

bool isVowel(char c) {
	return mo.find(c) != string::npos;
}

int main(){
	while(1){
		cin >> s;
		if (s == "end") break;
		memset(cnt, 0, sizeof(cnt));
		vcnt = lcnt = 0;
		for(int i=0; i<s.size(); i++){
			int k = s[i] - 'a';
			cnt[k]++;
			if(isVowel(s[i])) vcnt++, lcnt=0;
			else vcnt=0, lcnt++;
			if(vcnt == 3 || lcnt == 3) flag=1;
			if(i>=1 &&(s[i-1] == s[i]) && (k != e && k != o)) flag=1;
		}
		if(!cnt['a'-'a'] && !cnt['i'-'a'] && !cnt['u'-'a'] && !cnt['e'-'a'] && !cnt['o'-'a']) {
			flag = 1;
		}
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
		flag = 0;
	}
	return 0;
}
