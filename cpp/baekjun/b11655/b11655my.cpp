#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	getline(cin, s);
	for(int i=0; i<s.size();i++){
		if ( s[i] >= 'a' && s[i] <= 'z' ){
			s[i] = (((s[i] + 13) - 'a') % 26)+'a';
		}else if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = (((s[i] + 13) - 'A') % 26)+'A';
		}
	}
	cout << s << "\n";
	return 0;
}
