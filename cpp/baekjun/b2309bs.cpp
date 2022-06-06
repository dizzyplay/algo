#include <bits/stdc++.h>
using namespace std;
int a[9] = { 20, 7, 23, 19, 10, 15, 25, 8, 13};
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	sort(a, a+9);
	do {
		int result =0;
		for(int i=0; i<7; i++) result += a[i];
		if(result == 100) break;
	}while(next_permutation(a,a+9));
	for(int i=0; i<7; i++) cout << a[i] << '\n';
	return 0;
}
