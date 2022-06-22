#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int main(){
	while(cin >> n){
		int i=0;
		int ret = 1;
		while(1){
			i = ((i*10) + 1 )% n;
			if (i==0) break;
			ret ++;
		}
		cout << ret << endl;
	}
	return 0;
}
