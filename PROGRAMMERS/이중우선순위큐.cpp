/* https://programmers.co.kr/learn/courses/30/lessons/42628 */

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	multiset<int> heap;


	for (int i = 0; i < operations.size(); i++)	{
		if (operations[i][0] == 'I')		{

			string temp = operations[i].substr(1, operations[i].size());
			heap.insert(stoi(temp));
		}
		else if(!heap.empty()) {
			if (operations[i][2] == '1') {				
				heap.erase(--heap.end());
			}
			else { 
				heap.erase(heap.begin());
			}
		}
	}


	if (heap.empty()) {
		answer.resize(2, 0);
	}
	else{
		auto iter = heap.end();
		--iter;
		answer.push_back(*iter);
		answer.push_back(*(heap.begin()));
	}
	return answer;
}