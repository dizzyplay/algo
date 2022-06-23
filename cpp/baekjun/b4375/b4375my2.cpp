#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	while(cin >> n){
		string s = "1";
		int ret = 1;
		while(1){
			int r = stoi(s);
			if (r % n == 0) break;
			s = to_string(r % n) + "1";
			ret += 1;
		}
		cout << ret << endl;
	}
	return 0;
}
