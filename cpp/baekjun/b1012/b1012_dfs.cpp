#include <bits/stdc++.h>
using namespace std;
int k,m,n,ret, t;
int arr[51][51];
int visited[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (!visited[ny][nx] && arr[ny][nx] == 1) dfs(ny,nx);
	}
}

void initData(){
	fill(&arr[0][0],&arr[0][0]+51*51,0);
	fill(&visited[0][0],&visited[0][0]+51*51,0);
}

int main(){
	cin >> k;
	while(k) {
		cin >> m >> n >> t;
		for(int i=0; i<t; i++){
			int x,y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j] == 1 && !visited[i][j]) {
					dfs(i,j);
					ret++;
				}
			}
		}
		cout << ret << "\n";

		ret =0;
		initData();
		k--;
	}
	return 0;
}
