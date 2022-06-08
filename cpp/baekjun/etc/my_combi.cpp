#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void combi(int n){
	if (v.size() == 3) {
		for(auto x: v) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}
	for(int i=n; i<5; i++){
		v.push_back(i);
		combi(i+1);
		v.pop_back();
	}
}

int main(){
	combi(0);
	return 0;
}
