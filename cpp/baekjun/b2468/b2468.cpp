#include <bits/stdc++.h>
using namespace std;

int arr[100][100], visited[100][100];
int n,max_n,tret,ret;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void oflow(int x){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if (arr[i][j] <= x ) arr[i][j] = 0;
		}
	}
}
void dfs(int y,int x){
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		dfs(ny,nx);
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int a;
			cin >> a;
			max_n = max(a,max_n);
			arr[i][j] = a;
		}
	}

	for(int i=1; i<100; i++){
		for(int l=0; l<n; l++){
			for(int k=0; k<n; k++){
				if (arr[l][k] > 0 && !visited[l][k]) {
					dfs(l,k);
					tret ++;
				}
			}
		}
		ret = max(tret, ret);
		tret = 0;
		fill(&visited[0][0], &visited[0][0] + 100 * 100 ,0);
		oflow(i);
	}
	cout << ret << "\n";

	return 0;
}
