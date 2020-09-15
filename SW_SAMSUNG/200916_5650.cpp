#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 0,1,0,-1 }; // 상 우 하 좌 
int dy[] = { -1,0,1,0 };

int block[6][4] = { {0,0,0,0},{2,3,1,0},{1,3,0,2},{3,2,0,1},{2,0,3,1},{2,3,0,1} };

int N;
int sx, sy;
int map[102][102];

int answer;
int top;
vector<int> wormhole[11];

void simulation(int x, int y, int dir) {

	int nx = x;
	int ny = y;

	while (1) {

		nx += dx[dir];
		ny += dy[dir];

		if ((nx == sx && ny == sy) || (map[ny][nx] == -1))
			return;


		if (1 <= map[ny][nx] && map[ny][nx] <= 4) { // block인 경우

			top++;
			simulation(nx, ny, block[map[ny][nx]][dir]);

			return;
		}

		if (map[ny][nx] == 5) { // 벽인경우 갔던길을 시작점까지 되돌아감 
			top = top * 2 + 1;
			return;
		}

		if (6 <= map[ny][nx] && map[ny][nx] <= 10) {

			if (ny == wormhole[map[ny][nx]][0] && nx == wormhole[map[ny][nx]][1])
				simulation(wormhole[map[ny][nx]][3], wormhole[map[ny][nx]][2], dir);
			else
				simulation(wormhole[map[ny][nx]][1], wormhole[map[ny][nx]][0], dir);

			return;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {

		cout << "#" << i + 1 << " ";

		cin >> N;
		answer = 0;
		top = 0;

		for (int i = 0; i < 11; i++) {
			wormhole[i].clear();
		}

		for (int i = 0; i <= N + 1; i++) { // 외곽을 5번 블록으로
			map[0][i] = 5;
			map[i][0] = 5;
			map[N + 1][i] = 5;
			map[i][N + 1] = 5;
		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {

				int num;
				cin >> num;
				if (6 <= num && num <= 10) {
					wormhole[num].push_back(i);
					wormhole[num].push_back(j);
				}
				map[i][j] = num;

			}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {

				if (map[i][j] == 0) {

					for (int d = 0; d < 4; d++) {
						sx = j;
						sy = i;
						simulation(j, i, d);
						answer = max(answer, top);
						top = 0;
					}

				}
			}

		cout << answer << endl;

	}



}


