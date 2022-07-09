#include <bits/stdc++.h>
using namespace std;

int n,m,cmin,cmax,j,ret,d,v;

int main(){
	cin >> n >> m;
	cmin = 1;
	cmax = m;
	cin >> j;
	while(j){
		d =0;
		cin >> v;
		if (v < cmin){
			d = cmin - v;
			cmin -= d;
			cmax -= d;
		}else if (v > cmax){
			d = v - cmax;
			cmin += d;
			cmax += d;
		}
		ret += d;
		j--;
	}
	cout << ret;
	return 0;
}
