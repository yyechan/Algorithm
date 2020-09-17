#include <iostream>
#include <vector>

using namespace std;

int N, X;

int map[20][20];

void solve() {

	int sum = 0;

	cin >> N >> X;

	for (int y = 0; y < N; y++)  // 데이터 입력
		for (int x = 0; x < N; x++)
			cin >> map[y][x];


	for (int y = 0; y < N; y++) {

		bool flag = true;

		bool Check[21] = { 0, }; //경사로 중복체크 용

		for (int x = 0; x < N - 1; x++) {

			int cur = x;
			int next = x + 1;

			if (map[y][next] - map[y][cur] == -1) { //지형이 1만큼 낮아질때

				int height = map[y][next];

				for (int a = next; a < next + X; a++) {

					if (a < N) {
						if (map[y][a] != height || Check[a] == true) {
							flag = false;
							break;
						}
					}
					else {
						flag = false;
						break;
					}

					if (flag == true && a == next + X - 1) {
						for (int t = next; t < next + X; t++) {
							Check[t] = true;
						}
					}

				}

			}
			else if (map[y][next] - map[y][cur] == 1) { // 지형이 1만큼 높아질 때
				int height = map[y][cur];

				for (int a = cur; a > cur - X; a--) {

					if (a >= 0) {
						if (map[y][a] != height || Check[a] == true) {
							flag = false;

							break;
						}

					}
					else {
						flag = false;
						break;
					}

					if (flag == true && a == cur - X + 1) {
						for (int t = cur; t > cur - X; t--) {
							Check[t] = true;
						}
					}

				}

			}
			else if (map[y][next] - map[y][cur] == 0) {
				continue;
			}
			else { // 그 외에는 무조건 활주로 불가
				flag = false;
				break;
			}

			if (flag == false)
				break;
		}

		if (flag == true)
			sum++;

	} 
	
	//가로 세로 따로 체크

	for (int x = 0; x < N; x++) {
		bool flag = true;

		bool Check[21] = { 0, };

		for (int y = 0; y < N - 1; y++) {

			int cur = y;
			int next = y + 1;

			if (map[next][x] - map[cur][x] == -1) {

				int height = map[next][x];

				for (int a = next; a < next + X; a++) {
					if (a < N) {
						if (map[a][x] != height || Check[a] == true) {
							flag = false;
							break;
						}
					}
					else {
						flag = false;
						break;
					}

					if (flag == true && a == next + X - 1) {
						for (int t = next; t < next + X; t++) {
							Check[t] = true;
						}
					}
				}

			}
			else if (map[next][x] - map[cur][x] == 1) {

				int height = map[cur][x];

				for (int a = cur; a > cur - X; a--) {
					if (a >= 0) {
						if (map[a][x] != height || Check[a] == true) {
							flag = false;
							break;
						}

					}
					else {
						flag = false;
						break;
					}

					if (flag == true && a == cur - X + 1) {

						for (int t = cur; t > cur - X; t--)
							Check[t] = true;

					}
				}

			}
			else if (map[next][x] - map[cur][x] == 0) {
				continue;

			}
			else {
				flag = false;
				break;

			}

			if (flag == false)
				break;
		}

		if (flag == true)
			sum++;

	}

	cout << sum << endl;

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int TestCase;

	cin >> TestCase;

	for (int i = 0; i < TestCase; i++) {

		cout << "#" << i + 1 << " ";
		solve();
	}
    
}