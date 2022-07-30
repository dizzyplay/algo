#include <bits/stdc++.h>
using namespace std;

int n;
string ret;
vector<string> v;

void go(){
	if (ret.size() == 0) return;
	while(1){
		if(ret.size() && ret.front() == '0') ret.erase(ret.begin());
		else break;
	}

	if (ret.size()==0) ret = "0";
	v.push_back(ret);
	ret ="";
}

bool cmp(string a, string b){
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		ret = "";
		for(auto c: s){
			if(c < 58) ret += c;
			else go();
		}
		go();
	}

	sort(v.begin(), v.end(), cmp);
	for(auto n: v){
		cout << n << "\n";
	}
	return 0;
}
