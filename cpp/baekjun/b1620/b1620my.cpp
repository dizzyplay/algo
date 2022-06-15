// 168ms
#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
int n,k;
string s[100000];
string t;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> t;
		s[i]=t;
		m.insert({t, i});
	}

	for(int i=0; i<k; i++){
		cin >> t;
		if (t[0] >= 'A' && t[0] <= 'Z') {
			cout << m.find(t)->second << "\n";
		}else {
			cout << s[atoi(t.c_str())] << "\n";
		}
	}
	return 0;
}
