#include <bits/stdc++.h>
using namespace std;

pair<string,string> split(string inp, char delimiter){
	string r,e;
	int i=0;;
	for(; i<inp.size(); i++){
		if (inp[i] != delimiter) r.push_back(inp[i]);
		else break;
	}
	for(i+=1;i<inp.size(); i++){
		e.push_back(inp[i]);
	}
	return make_pair(r,e);
}

string p,s;
vector<string> arr;
int n,flag;
int main(){
	cin >> n;
	cin >> p;
	pair<string,string> v = split(p,'*');
	for(int i=0; i<n; i++){
		cin >> s;
		arr.push_back(s);
	}
	for(int i=0; i<n; i++){
		flag = 0;
		if(arr[i].size() < v.first.size() + v.second.size()) {
			cout << "NE" << "\n";
			continue;
		}
		for(int j=0; j<v.first.size(); j++){
			if(arr[i][j] != v.first[j]) {
				cout << "NE" << "\n";
				flag = 1;
				break;
			}
		}
		if(!flag) {
			reverse(arr[i].begin(), arr[i].end());
			reverse(v.second.begin(), v.second.end());
			for(int j=0; j<v.second.size(); j++){
				if(v.second[j] != arr[i][j] ) {
					cout << "NE" << "\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag) continue;
		cout << "DA" << "\n";
	}

	return 0;
}
