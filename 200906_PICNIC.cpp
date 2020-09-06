#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M;

bool isMatched[10];

int answer;

void dfs(vector<vector<int>> &vec , int dep ,int C) {

	if (dep == N / 2) {

		answer++;
		return;

	}


	for (int i = C; i < N; i++) {

		if(isMatched[i] == false)
			for (int j = 0; j < vec[i].size(); j++) {

				if (isMatched[vec[i][j]] == false) {

					isMatched[i] = isMatched[vec[i][j]] = true;
					dfs(vec, dep + 1,i+1);
					isMatched[i] = isMatched[vec[i][j]] = false;
				}

			}

	}


}



void solve() {

	answer = 0;
	memset(isMatched, 0, sizeof(isMatched));
	cin >> N >> M;

	vector<vector<int>> vec(N);



	for (int i = 0; i < M; i++) {

		int n1, n2;

		cin >> n1 >> n2;

		vec[min(n1, n2)].push_back(max(n1, n2));

	}


	dfs(vec, 0,0);


	cout << answer << endl;

}


int main(int argc, char** argv) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;

	for (int i = 1; i <= T; i++) {
		solve();
	}

	return 0;

}