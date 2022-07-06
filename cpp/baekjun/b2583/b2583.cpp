#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,d;
int arr[101][101];
int cnt,temp;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
vector<int> ret;

void printA(){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int y, int x){
	arr[y][x] = 1;
	temp += 1;
	for(int i=0; i<4; i++){
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
		if(arr[ny][nx] == 1) continue;
		dfs(ny,nx);
	}
}

int main(){
	cin >> m >> n >> k;
	for(int i=0; i<k; i++){
		cin >> a >> b >> c >> d;
		for(int ii=m-d; ii<m-b; ii++){
			for(int jj=a; jj<c; jj++){
				arr[ii][jj]  = 1;
			}
		}
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if (arr[i][j] == 0) {
				dfs(i,j);
				ret.push_back(temp);
				temp=0;
			}
		}
	}

	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for( auto n : ret) {
		cout << n << " ";
	}

	return 0;
}
