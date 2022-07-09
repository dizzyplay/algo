#include <bits/stdc++.h>
using namespace std;

int n;
string arr[65][65];

string quard(int y, int x, int size){
	if(size==1) return arr[y][x];
	string t = arr[y][x];
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(t != arr[i][j]){
				string ret;
				size = size / 2;
				ret += "(";
				ret += quard(y,x,size);
				ret += quard(y,x+size,size);
				ret += quard(y+size,x,size);
				ret += quard(y+size,x+size,size);
				ret += ")";
				return ret;
			}
		}
	}
	return t;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<n; j++){
			arr[i][j] = s[j];
		}
	}

	cout << quard(0,0,n);
	return 0;
}
