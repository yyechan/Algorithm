/* https://programmers.co.kr/learn/courses/30/lessons/42584 */

// 별로 좋은 코드는 아님..

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {

	vector<int> answer;
	answer.resize(prices.size());

	vector<pair<int, int>> temp;
	int time = 0;

	for (int i = 0; i < prices.size(); i++) {

		auto iter = temp.end();
		while (iter > temp.begin()) {
			iter--;
			if (prices[i] < iter->first) {

				answer[iter->second] = time - iter->second;
				iter = temp.erase(iter);
			}
			else
				break;
		}

		temp.push_back(make_pair(prices[i], i));

		if (i == prices.size() - 1) {
			for (auto iter = temp.begin(); iter != temp.end(); iter++) {
				answer[iter->second] = time - iter->second;
			}

			break;
		}
		time++;
	}
	return answer;
}