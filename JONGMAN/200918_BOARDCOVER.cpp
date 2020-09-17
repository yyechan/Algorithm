/* main idea : 왼쪽상단 부터 채워나가 순서 중복 제거 */

#include <iostream>
using namespace std;

int H, W, answer;
char map[20][20];


int block[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{-1,1}}
};   // x,y 순

bool blockCheck(int x, int y, int dir) {

	bool flag = true;

	for (int i = 0; i < 3; i++) {
		int nx = x + block[dir][i][0];
		int ny = y + block[dir][i][1];

		if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
			return false;
		}
		if (map[ny][nx] == '#') {
			return false;
		}
	}

	return flag;
}

void blockDraw(int x, int y, int dir) {

	for (int i = 0; i < 3; i++) {
		int nx = x + block[dir][i][0];
		int ny = y + block[dir][i][1];

		if (map[ny][nx] == '#')
			map[ny][nx] = '.';
		else
			map[ny][nx] = '#';
	}
}

void dfs(int cnt, int goal) {

	if (cnt == goal) {
		answer++;
		return;
	}

	for (int curY = 0; curY < H; curY++)
		for (int curX = 0; curX < W; curX++) {

			if (map[curY][curX] == '.') { // 4개의 도형 시도 후 return 
										  // 안 멈출 경우 도형을 채우는 순서만 다른 중복발생
				for (int i = 0; i < 4; i++) {
					if (blockCheck(curX, curY, i) == true) {
						blockDraw(curX, curY, i);
						dfs(cnt + 1, goal);
						blockDraw(curX, curY, i);
					}
				}
				return;
			}
		}	
}

void solve() {

	int white = 0;
	answer = 0;

	cin >> H >> W;

	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
			if (map[y][x] == '.') 
				white++;
		}

	if (white % 3 != 0) {
		cout << 0 << endl;
		return;
	}

	dfs(0, white / 3);
	cout << answer << endl;
}


int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}