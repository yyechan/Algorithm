#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

class Cell
{

public:

	Cell() {
		isActive = false;
		isCell = false;
	}

	bool operator< (const Cell& a) const {

		return this->Life < a.Life;
	}

	int activeTime;
	int lifeTime;
	int Life;
	bool isActive;
	bool isCell;
	int x;
	int y;
};


int main() {

	int TestCase;
	cin >> TestCase;
	vector<int> answer;
		

	for (int i = 0; i < TestCase; i++) {

		vector<vector<bool>> Check(400, vector<bool>(400, false));
		vector<Cell> NonActive;
		int N, M, K;
		priority_queue<Cell> queue;

		cin >> N >> M >> K;

		int start_x = 200 - M / 2;
		int start_y = 200 - N / 2; 

		for (int y = start_y; y < N + start_y; y++)	{
			for (int x = start_x; x < M + start_x; x++)	{
				int num = 0;
				Cell cell;
				cin >> num;

				if (num == 0) {
					continue;
				}
				else {
					cell.activeTime = num;
					cell.Life = num;
					cell.isCell = true;
					cell.x = x;
					cell.y = y;
					NonActive.push_back(cell);
					Check[y][x] = true;
				}
			}
		}

		for (int time = 0; time < K; time++) {


			for (vector<Cell>::iterator iter = NonActive.begin(); iter != NonActive.end(); ) {

				if (iter->isCell) {
									   
					if (iter->isActive == false) {
											   
						if (iter->activeTime == 0) {
							queue.push(*iter);
							iter->isActive = true;
							iter->lifeTime = iter->Life;
						}
						else
							iter->activeTime--;
					}

					if (iter->isActive) {

						iter->lifeTime--;

						if (iter->lifeTime == 0) {
							iter = NonActive.erase(iter);
							continue;
						}
					}
				}

				iter++;

			}


			while (!queue.empty()) {


				Cell temp = queue.top();
				queue.pop();

				for (int a = 0; a < 4; a++) {
					if (Check[temp.y + dy[a]][temp.x + dx[a]] == false) {

						Check[temp.y + dy[a]][temp.x + dx[a]] = true;

						Cell cell;
						cell.isCell = true;
						cell.Life = temp.Life;
						cell.activeTime = temp.Life;
						cell.isActive = false;
						cell.x = temp.x + dx[a];
						cell.y = temp.y + dy[a];
						NonActive.push_back(cell);
					}


				}

			}

		}

		int Count = 0;
		for (int j = 0; j < NonActive.size(); j++) {

			if (NonActive[j].isCell) {
				Count++;
			}
		}

		answer.push_back(NonActive.size());

	}

	for (int i = 0; i < answer.size(); i++) {


		cout << "#" << i + 1 << " ";

		cout << answer[i] << "\n";
	}


}
