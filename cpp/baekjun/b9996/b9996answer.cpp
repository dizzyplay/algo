#include <bits/stdc++.h>
using namespace std;

int n;
string s,p;
int main(){
	cin >> n;
	cin >> p;
	int pos = p.find('*');
	string front = p.substr(0, pos);
	string tail = p.substr(pos+1,p.size());
	for(int i=0; i<n; i++){
		cin >> s;
		if (front.size() + tail.size() > s.size()) cout << "NE\n";
		else {
			if (front == s.substr(0,front.size()) && tail == s.substr(s.size() - tail.size())) {
				cout << "DA\n";
			}else cout << "NE\n";
		}
	}

	return 0;
}
