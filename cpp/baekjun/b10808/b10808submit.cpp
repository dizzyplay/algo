//https://www.acmicpc.net/submit/10808
#include <map>
#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	map<char, int> m;
	for(int i=0; i < 25; i++) m[(char)i+97] = 0;
	for(char c : s) m[c]++;
	for(auto v: m) cout << v.second << " ";
	return 0;
}
