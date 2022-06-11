#include <bits/stdc++.h>
using namespace std;

string s;
bool palin(int a, int b){
	if (a >= b) return true;
	if (s[a] != s[b] ) return false;
	return palin(a+1, b-1);
}

int main(){
	while(1){
		cin >> s;
		cout << palin(0,s.size() -1) << "\n";
	}
	return 0;
}
