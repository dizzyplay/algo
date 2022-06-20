// int의 범위를 넘어서기 떄문에 long long <- int * 3 은 넘어섬
// 어떤 값을 어떤수로 나눈 나머지의 곱을 해당 수로 나누었을떄 의 값은 원래수를 어떤수로 나누었을떄의 값과 같다
// (((나머지 * 나머지 ) % 나룰수 ) * 원래수 ) % 나눌수 <- 홀수상황
// (((1 * 1) % 4) * 11) % 4 = 3
// (((나머지 * 나머지 ) % 나눌수 ) * 나머지 ) % 나눌수 <- 이렇게하면 다른 결과가 나옴
// (((1 * 1) % 4) * 1 ) % 4 = 1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
// 맞는답
ll go(ll a,ll b) {
	if (b<=1) return a % c;
	ll ret = go(a,b/2);
	ret = (ret * ret ) % c;
	if (b&1) {
		cout << ret << " "  << a <<endl;
		ret = (ret * a) % c;
	}
	return ret;
}

// 틀린닶
ll go2(ll a,ll b) {
	if (b<=1) return a % c;
	ll ret = go(a,b/2);
	ret = (ret * ret ) % c;
	if (b&1) {
		cout << ret << " "  << ret <<endl;
		ret = (ret * ret) % c;
	}
	return ret;
}
int main(){
	cin >> a >> b >> c;
	cout << go(a,b) << "\n";
	cout << "----------------" << endl;
	cout << go2(a,b) << "\n";
	return 0;
}
