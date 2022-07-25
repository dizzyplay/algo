#include <bits/stdc++.h>
using namespace std;

vector<string> result;
int n;
string num = "0123456789";

bool cmp(string a, string b){
	if(a.size() == b.size()) {
		for(int i=0; i < a.size(); i++){
			if (a[i] == b[i]) continue;
			return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}

string deleteZero(string s){
	if (s.size() == 1) return s;
	if(s[0] == '0') {
		return deleteZero(s.substr(1,s.size()-1));
	}
	return s;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string s,temp;
		cin >> s;
		for(auto c: s){
			if (num.find(c) != string::npos){
				temp.push_back(c);
			}
			if (num.find(c) == string::npos && temp.size() > 0) {
				result.push_back(deleteZero(temp));
				temp = "";
			}
		}
		if(temp.size() > 0) {
			result.push_back(deleteZero(temp));
		}
	}
	sort(result.begin(), result.end(),cmp);
	for(auto n: result){
		cout << n << endl;
	}
	return 0;
}
