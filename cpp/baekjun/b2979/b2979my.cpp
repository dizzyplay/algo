//https://www.acmicpc.net/problem/2979
#include <bits/stdc++.h>
using namespace std;

int arr[104];
int a,b,c,q,w,ret;

int main(){
	cin >> a >> b>> c;
	for(int i=0; i<3; i++) {
		cin >> q >> w;
		for(int j=q; j<w; j++) arr[j]++;
	}
	for(auto n : arr)  {
		if (n == 1) ret += a;
		else if (n==2) ret += b * 2;
		else if (n==3) ret += c * 3;
	}

	cout << ret << "\n";
	return 0;
}
