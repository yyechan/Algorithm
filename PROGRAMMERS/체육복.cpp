/* https://programmers.co.kr/learn/courses/30/lessons/42862 */

#include <string>
#include <vector>

using namespace std;

int status[30];


int solution(int n, vector<int> lost, vector<int> reserve) {

	int answer = 0;
	
	for (int i = 0; i < lost.size(); i++) 
		status[lost[i]]--;
	
	for (int i = 0; i < reserve.size(); i++) 
		status[reserve[i]]++;

	for (int i = 0; i < n; i++) {
		if (status[i] == -1) {
			if (i != 0) {
				if (status[i - 1] == 1) {
					status[i - 1]--;
					status[i]++;
					continue;
				}
			}

			if (i != n) {
				if (status[i + 1] == 1) {
					status[i + 1]--;
					status[i]--;
					continue;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (status[i] != 0) {
			answer++;
		}
	}
	return answer;
}
