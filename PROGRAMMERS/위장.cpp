#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	map<string, int> Map;
	for (int i = 0; i < clothes.size(); i++)	{
		string key = clothes[i][1];

		if (Map.find(key) != Map.end())	{
			Map.find(key)->second++;
		}
		else {
			Map.insert(make_pair(key, 1));
		}
	}

	int sum = 1;
	for (auto iter : Map)	{
		sum *= iter.second+1;
	}    
  
	answer = sum-1; // 전체 경우의 수에서 아무것도 안 입는 경우 -1
	return answer;
  
}
