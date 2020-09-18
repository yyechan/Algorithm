/* https://programmers.co.kr/learn/courses/30/lessons/42579 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> vec1, pair<int, int> vec2) {
	if (vec1.first == vec2.first) {
		return vec1.second < vec2.second;
	}
	return vec1.first > vec2.first;
}


class info {

public:
	info(int a1, int a2) {
		this->play = a1;
		this->index = a2;
	}

	bool operator<(const info& rhs) {
		if (this->play == rhs.play) {
			return this->index < rhs.index;
		}
		else {
			return this->play > rhs.play;
		}

	}
	int play;
	int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;
	map < string, pair<int, vector<info>>> Map;

	for (int i = 0; i < genres.size(); i++) {
		Map[genres[i]].first += plays[i];
		Map[genres[i]].second.push_back(info(plays[i], i));
	}

	vector<pair<int, string>> vec;

	for (auto iter = Map.begin(); iter != Map.end(); iter++)
		vec.push_back(make_pair(iter->second.first, iter->first));


	sort(vec.rbegin(), vec.rend());
	vector<vector<info>> final;

	for (int i = 0; i < vec.size(); i++) {
		string genre = vec[i].second;
		sort(Map[genre].second.begin(), Map[genre].second.end());
		for (int j = 0; j < Map[genre].second.size() && j < 2; j++)
			answer.push_back(Map[genre].second[j].index);
	}
	return answer;
}