#include <bits/stdc++.h>
using namespace std;

string s;
bool palin(int a, int b){
	if (s[a] != s[b] ) return false;
	if (a == b-1) return true;
	if (a ==b) return true;
	return palin(a+1, b-1);
}

int main(){
	cin >> s;
	cout << palin(0,s.size() -1);
	return 0;
}
