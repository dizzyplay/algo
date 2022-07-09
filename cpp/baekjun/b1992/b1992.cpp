#include <bits/stdc++.h>
using namespace std;

int n, arr[65][65];

string quard(int size, int y, int x){
	if (size == 1) return string(1,arr[y][x]);
	char temp = arr[y][x];
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(temp != arr[i][j]){
				string ret;
				size = size/2;
				ret += "(";
				ret += quard(size, y,x);
				ret += quard(size, y,x+size);
				ret += quard(size, y+size,x);
				ret += quard(size, y+size,x+size);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1,arr[y][x]);
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++){
			arr[i][j] = s[j];
		}
	}
	cout << quard(n,0,0);
	return 0;
}
