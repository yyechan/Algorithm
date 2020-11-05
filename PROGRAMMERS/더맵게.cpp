/* https://programmers.co.kr/learn/courses/30/lessons/42626 */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> heap;

	for (int i = 0; i < scoville.size(); i++)
		heap.push(scoville[i]);

	int count_num = 0;

	while (1){
        
		if (heap.top() >= K) {
			answer = count_num;
			break;
		}

		if (heap.size() == 1){
			answer = -1;
			break;
		}

		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();

		heap.push(a + (b * 2));
		count_num++;
	}


	return answer;
}