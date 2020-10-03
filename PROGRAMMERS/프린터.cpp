/* https://programmers.co.kr/learn/courses/30/lessons/42587 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {

	int answer;
	vector<int> answer_vec;
	vector<pair<int, int>> que;

	for (int i = 0; i < priorities.size(); i++)
		que.push_back(make_pair(priorities[i], i));

	while (!que.empty()) {
		int value = que[0].first;
		int index = que[0].second;
		bool flag = false;

		que.erase(que.begin());

		for (auto iter = que.begin(); iter != que.end(); iter++) {

			if (value < iter->first)			{
				que.push_back(make_pair(value, index));
				flag = true;
				break;
			}
		}

		if (flag == false)
			answer_vec.push_back(index);
	}

	for (int i = 0; i < answer_vec.size(); i++)	{
		if (answer_vec[i] == location)	{
			answer = i + 1;
		}
	}
    
	return answer;
}