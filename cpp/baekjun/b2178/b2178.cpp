#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[104][104];
int x,y;

void bfs(){
	queue<pair<int,int>> q;
	q.push({1, 1});
	while(q.size() > 0) {
		tie(y,x) = q.front();
		//cout << y << x << " " << arr[y][x] << endl;
		q.pop();
		if(arr[y + 1][x] == 1){
			q.push({y+1, x});
			arr[y+1][x] = arr[y][x] + 1;
		}
		if(arr[y][x+1] == 1){
			q.push({y,x+1});
			arr[y][x+1] = arr[y][x] + 1;
		}
		if(arr[y-1][x] == 1){
			q.push({y-1,x});
			arr[y-1][x] = arr[y][x] + 1;
		}
		if(arr[y][x-1] == 1){
			q.push({y,x-1});
			arr[y][x-1] = arr[y][x] + 1;
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		string s;
		cin >> s;
		for(int j=1; j<=m; j++){
			arr[i][j] = s[j-1] - '0';
		}
	}
	bfs();
	//for(int i=1; i<=n; i++){
	//	for(int j=1; j<=m; j++){
	//		cout << arr[i][j];
	//	}
	//	cout << endl;
	//}
	cout << arr[n][m];

	return 0;
}
