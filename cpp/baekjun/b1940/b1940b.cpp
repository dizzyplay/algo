// test case
// 3
// 2
// 1 1 1
// 넣으면 답으로 3이 나오는데
// 1이 나와야 맞는거 아닌가???..
#include <bits/stdc++.h>
using namespace std;

int n,m,ret;
int cnt[150001];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> cnt[i];
	}

	sort(cnt, cnt+n);

	for(int i=0; i < n; i++){
		for(int j=i+1; j< n; j++){
			if (cnt[i] + cnt[j] == m) ret++;
		}
	}

	cout << ret;

	return 0;
}
