#include <bits/stdc++.h>
using namespace std;

int n,ret;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		stack<char> _stack;
		cin >> s;
		for(auto c: s){
			if (_stack.size() == 0) _stack.push(c);
			else {
				if (_stack.top() == c) _stack.pop();
				else _stack.push(c);
			}
		}
		if(_stack.empty()) ret++;
	}
	cout << ret << "\n";
	return 0;
}
