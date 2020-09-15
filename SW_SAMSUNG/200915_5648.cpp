#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int sum;
int dx[] = { 0,0,-1,1 }; //상 하 좌 우
int dy[] = { 1,-1,0,0 };
bool Check[4002][4002];


class Atom {

public:

	Atom(int x, int y, int dir, int power) {
		this->pos.first = x;
		this->pos.second = y;
		this->power = power;
		this->dir = dir;
	}

	pair<int, int> pos;
	int dir;
	int power;

};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int TestCase;

	cin >> TestCase;

	vector<int> answer;

	for (int i = 0; i < TestCase; i++) {
		sum = 0;

		vector<pair<int, int>> collisionXY;
		list<Atom> queue;
		//vector<vector<int>> Check(4002, vector<int>(4002, 0));
		int N;
		cin >> N;
		for (int n = 0; n < N; n++) {

			int X, Y, D, P;

			cin >> X >> Y >> D >> P;

			//	Check[(Y + 1000) * 2][(X + 1000) * 2] = 1;

			Atom temp((X + 1000) * 2, (Y + 1000) * 2, D, P);

			queue.push_back(temp);
		}

		while (!queue.empty()) {

			for (list<Atom>::iterator iter = queue.begin(); iter != queue.end(); ) {

				int nx = iter->pos.first + dx[iter->dir];
				int ny = iter->pos.second + dy[iter->dir];

				iter->pos.first = nx;
				iter->pos.second = ny;

				if (0 <= nx && nx < 4002 && 0 <= ny && ny < 4002) {
					if (Check[ny][nx] == 1) {
						collisionXY.push_back(make_pair(nx, ny));

					}
					else {
						Check[ny][nx]++;
					}

				}
				else {
					iter = queue.erase(iter);
					continue;
				}
				iter++;

			}

			while (!collisionXY.empty()) {
				pair<int, int> col_pos = collisionXY.back();
				collisionXY.pop_back();

				for (list<Atom>::iterator iter = queue.begin(); iter != queue.end();) {



					if (iter->pos == col_pos) {
						Check[iter->pos.second][iter->pos.first] = 0;
						sum += iter->power;
						iter = queue.erase(iter);
					}
					else {
						iter++;
					}
				}

			}

			for (list<Atom>::iterator iter = queue.begin(); iter != queue.end(); iter++) {
				Check[iter->pos.second][iter->pos.first] = 0;
			}
		}

		answer.push_back(sum);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << "#" << i + 1 << " ";
		cout << answer[i] << "\n";
	}





}


