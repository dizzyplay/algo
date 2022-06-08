#include <bits/stdc++.h>
using namespace std;

string s = "baekjook";

int main(){
	map<char, int> m;
	for(int i =0; i<26; i++){
		m[(char)i+97] = 0;
	}
	for(char c : s) {
		m[c] = m[c] +1;
	}
	for(auto c: m) {
		cout << c.second << " ";
	}
	return 0;
}
