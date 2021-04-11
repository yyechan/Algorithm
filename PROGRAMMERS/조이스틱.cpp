#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Alpha(char alpha) {
	return alpha - 'A' < 'A' - alpha + ('Z' - 'A') ? alpha - 'A' : 'A' - alpha + ('Z' - 'A') + 1;
}

int solution(string name) {
	int answer = 0;
	vector<int> needToChange;
	vector<pair<int, int>> temp;
	vector<int> ppoint;
	int mid = name.size() / 2;
	int startPoint = 0;
	int endPoint = 0;
	int point = 0;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') {
			needToChange.push_back(i);
			point += Alpha(name[i]);
		}
	}

	for (int i = 0; i < needToChange.size() - 1; i++) {
		temp.push_back(make_pair(needToChange[i], needToChange[i + 1]));
	}

	int straight = needToChange[needToChange.size() - 1];

	for (int i = 0; i < temp.size(); i++) {
		int goback = temp[i].first * 2 + name.size() - temp[i].second;
		ppoint.push_back(straight < goback ? straight : goback);
	}
	point += *min_element(ppoint.begin(), ppoint.end());
	return point;
}