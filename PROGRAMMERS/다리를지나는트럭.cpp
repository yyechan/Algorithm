/* https://programmers.co.kr/learn/courses/30/lessons/42583 */
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

	int answer = 0;
	int weight_sum = 0;
	vector<pair<int, int>> que;

	do	{

		if (!que.empty()) {
			for (int i = 0; i < que.size(); i++) {
				que[i].second--;
			}

			for (auto iter = que.begin(); iter != que.end(); iter++) {

				if (iter->second == 0) {
					weight_sum -= iter->first;
					iter = que.erase(iter);
					break;
				}
			}
		}

		if (!truck_weights.empty()) {
			auto iter = truck_weights.begin();

			if (weight_sum + *iter <= weight) {
				weight_sum += *iter;
				que.push_back(make_pair(*iter, bridge_length));
				iter = truck_weights.erase(iter);
			}
		}
		answer++;

	} while (!que.empty());

	return answer;
}