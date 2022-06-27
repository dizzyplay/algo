#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int visited[max_n][max_n], m,n,arr[max_n][max_n],x,y;
int dy[4] = { -1, 0 , 1 , 0};
int dx[4] = { 0, -1, 0, 1};

int main() {
	queue<pair<int,int>> _q;
	visited[0][0] = 1;
	cin >> n >> m;
	for(int i=0; i < n; i++){
		string s;
		cin >> s;
		for(int j=0; j < m; j++){
			arr[i][j] = s[j] - '0';
		}
	}

	_q.push({0,0});
	while(_q.size() > 0) {
		tie(y,x) = _q.front();_q.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + y;
			int mx = dx[i] + x;
			if (arr[ny][mx] == 0 || ny < 0 || ny >= n || mx < 0 || mx >= m || visited[ny][mx] != 0) continue;
			visited[ny][mx] = visited[y][x] + 1;
			_q.push({ny,mx});
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << visited[n-1][m-1];
	return 0;
}
