/*  https://programmers.co.kr/learn/courses/30/lessons/42586  */

/* 시간 복잡도 최악 O(100N), O(1N) 풀이법도 존재 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;

	while (!progresses.empty())	{
		for (int i = 0; i < progresses.size(); i++)	
			progresses[i] += speeds[i];
        
		auto iter1 = progresses.begin();
		auto iter2 = speeds.begin();
        
		int p_count = 0;

		while (*iter1 >= 100 && iter1 != progresses.end()) {
			iter1 = progresses.erase(iter1);
			iter2 = speeds.erase(iter2);
			p_count++;
		}

		if(p_count !=0)
		answer.push_back(p_count);
	}

	return answer;

}
