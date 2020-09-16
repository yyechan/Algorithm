#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0,1,0,-1 }; // 제자리, 상 하 좌 우
int dy[] = { 0,-1,0,1,0 };

int Amove[100];
int Bmove[100];

int M, A;

class AP {

public:

	AP(int x, int y, int range, int power) {
		this->pos.first = x;
		this->pos.second = y;
		this->range = range;
		this->power = power;
	}


	pair<int, int> pos;
	int range;
	int power;
};

void solve() {

	vector<AP> ap;

	cin >> M >> A;

	for (int i = 0; i < M; i++)
		cin >> Amove[i];

	for (int i = 0; i < M; i++)
		cin >> Bmove[i];

	for (int i = 0; i < A; i++) {

		int x, y, r, p;
		cin >> x >> y >> r >> p;
		ap.push_back(AP(x, y, r, p));
	}



	int Ax, Ay, Bx, By;

	Ax = 1;
	Ay = 1;
	Bx = 10;
	By = 10;

	int sum = 0;

	for (int m = 0; m <= M; m++) {

		vector<int> possible_a;
		vector<int> possible_b;

		for (int p = 0; p < ap.size(); p++) {
			if (abs(Ax - ap[p].pos.first) + abs(Ay - ap[p].pos.second) <= ap[p].range)
				possible_a.push_back(p);

			if (abs(Bx - ap[p].pos.first) + abs(By - ap[p].pos.second) <= ap[p].range)
				possible_b.push_back(p);
		}

		int Max = 0;

		if (possible_a.size() > 0 && possible_b.size() > 0) { 

			for (int a = 0; a < possible_a.size(); a++) { 

				for (int b = 0; b < possible_b.size(); b++) {

					int	temp = 0;

					if (possible_a[a] == possible_b[b]) {
						temp = ap[possible_a[a]].power;

					}
					else {
						temp += ap[possible_a[a]].power;
						temp += ap[possible_b[b]].power;
					}

					Max = max(Max, temp);
				}

			}
			sum += Max;
		}
		else if (possible_a.size() > 0) {
			int temp = 0;

			for (int q = 0; q < possible_a.size(); q++)
				temp = max(temp, ap[possible_a[q]].power);

			sum += temp;

		}
		else if (possible_b.size() > 0) {
			int temp = 0;

			for (int q = 0; q < possible_b.size(); q++)
				temp = max(temp, ap[possible_b[q]].power);


			sum += temp;
		}

		Ax = Ax + dx[Amove[m]];
		Ay = Ay + dy[Amove[m]];
		Bx = Bx + dx[Bmove[m]];
		By = By + dy[Bmove[m]];

	}

	cout << sum << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " ";
		solve();
	}




}