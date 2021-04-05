/* https://programmers.co.kr/learn/courses/30/lessons/42842 */

#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int red) 
{
	vector<int> answer;

	int sum = brown + red;

	int start = ceil(sqrt(sum));

	for (int row = start; row <= sum; row++) {

		int col = sum / row;

		if (row*col == sum) {

			if (row < col || row < 3)
				continue;

			if ((row - 2) * (col - 2) == red) {
				answer.push_back(row);
				answer.push_back(col);
			}
		}
	}
    
	return answer;
}