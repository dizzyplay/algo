#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int dx = 1;
int h,w;

void bfs(int y,int x, int level){
	if(arr[y][x+dx] == 0) return;;
	if (y >= h || x+dx >= w) return;
	arr[y][x+dx] = level + 1;
	bfs(y, x+dx, level + 1);
}

int main(){
	cin >> h >> w;
	for(int i=0; i<h; i++){
		string s;
		cin >> s;
		for(int j=0; j<w; j++){
			if (s[j] == '.') {
				arr[i][j]= -1;
			}else if (s[j] == '0') {
				arr[i][j] = 0;
			}
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(arr[i][j] == 0) bfs(i,j,0);
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
