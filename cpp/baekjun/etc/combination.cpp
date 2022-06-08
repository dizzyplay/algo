#include <bits/stdc++.h>
using namespace std;
int main(){
	const int r = 2;
	vector <char> arr{'a','b','c','d'};
	vector <bool> temp(arr.size(),false);
	for(int i=0; i<r; i++) temp[i] = true;
	do {
		for(int i=0 ; i <arr.size(); i++) {
			if (temp[i]) cout << arr[i] << ' ';
		}
		cout << '\n';
		for(auto n : temp) cout << n;
		cout << '\n';
	}while(prev_permutation(temp.begin(), temp.end()));
	return 0;
}
