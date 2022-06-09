#include <bits/stdc++.h>
using namespace std;
int A,B,C,a,b,cnt[104], ret;

int main() {
	cin >> A >> B >> C;
	for(int i=0; i<3; i++){
		cin >> a >> b;
		for(int j=a; j<b; j++) cnt[j]++;
	}
	for(auto n : cnt){
		if(n) {
			if(n==1) ret += A;
			else if(n==2) ret += B * 2;
			else if(n==3) ret += C * 3;
		}
	}
	cout << ret << "\n";
	return 0;
}
