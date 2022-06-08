#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> r;
int m=7;
int a[9];

bool combi(int l){
    if (r.size()==m){
        vector<int> result;
        for(auto n: r){
            result.push_back(a[n]);
        }
        if (100 == accumulate(result.begin(), result.end(),0)){
            sort(result.begin(), result.end());
            for(auto n: result){
                cout << n << endl;
            }
            return 1;
        }
        return 0;
    }

    for(int i=l; i<9; i++){
        r.push_back(i);
        bool f = combi(i+1);
        if (f) return 1;
        r.pop_back();
    }
	return 0;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0; i<9; i++){
		cin >> a[i];
	}
    combi(0);
    return 0;
}
