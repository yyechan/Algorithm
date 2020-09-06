#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[16];

int Min;

bool connected[10][16] = {

{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0},

};

bool check() {

	for (int i = 0; i < 12; i++) {

		if (map[i] != 12)
			return false;

	}

	return true;

}

void push(int idx) {

	for (int i = 0; i < 16; i++) {

		if (connected[idx][i]) {
			map[i] = map[i] % 12 + 3;
		}
	}
}

void dfs(int depth, int cnt ) {
	
	if (depth == 10) {

		if (check()) {
			Min = min(Min, cnt);
		}

		return;

	}
	for (int i = 0; i < 4; i++) {

		dfs(depth + 1, cnt + i);
		push(depth);

	}
}

void solve() {

	Min = 987654321;

	for (int i = 0; i < 16; i++) {
		cin >> map[i];
	}

	dfs(0,0);

	if (Min == 987654321)
		cout << -1 << endl;
	else
	    cout << Min << endl;

}


int main(int argc, char** argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;

	for (int i = 1; i <= T; i++) 
		solve();
	

	return 0;

}