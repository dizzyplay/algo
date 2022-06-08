#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int cnt[26];
int main(){
	cin >> s;
	for(char a: s)  cnt[a-'a']++;
	for(auto n: cnt) cout << n << " ";
	return 0;
}
