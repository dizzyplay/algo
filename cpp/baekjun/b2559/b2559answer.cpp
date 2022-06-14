// 이게 내 풀이보다 메모리를 조금더 적게먹네 왜..?
#include <bits/stdc++.h>
using namespace std;

int n,k, psum[100004], temp,ret=-10000000;
int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> temp;
		psum[i] = psum[i-1] + temp;
	}
	for(int i=k; i<=n; i++){
		ret = max(ret, psum[i] - psum[i-k]);
	}
	cout << ret;
	return 0;
}

// 큰돌풀이
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int n, k, temp, psum[100001], ret = -10000004;
//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);cout.tie(NULL);
//	cin >> n >> k;
//	for(int i = 1; i <= n; i++){
//		cin >> temp; psum[i] = psum[i - 1] + temp;
//	}
//	for(int i = k; i <= n; i++){
//		ret = max(ret, psum[i] - psum[i - k]);
//	}
//	cout << ret << "\n";
//    return 0;
//}
