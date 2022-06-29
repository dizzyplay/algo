#include <bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4] = {0,-1,0,1};
const int msize=50;
int arr[msize][msize];
int ret,m,n,k;

void bfs(int y, int x){
	queue<pair<int,int>> _q;
	_q.push({y,x});
	while(_q.size() > 0 ){
		tie(y,x) = _q.front(); _q.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + y;
			int mx = dx[i] + x;
			if(ny < 0 || mx < 0 || arr[ny][mx] == 0) continue;
			if(ny >= n || mx >= m) continue;
			arr[ny][mx] = 0;
			_q.push({ny,mx});
		}
		arr[y][x] = 0;
	}
	ret += 1;
}

int main(){
	int t_count;
	cin >> t_count;

	for(int tc=0; tc<t_count; tc++){
		cin >> m >> n >> k;
		for(int i=0; i<k; i++){
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if (arr[i][j] == 1) bfs(i,j);
			}
		}
		cout << ret << "\n";
		ret = 0;
	}

	return 0;
}
