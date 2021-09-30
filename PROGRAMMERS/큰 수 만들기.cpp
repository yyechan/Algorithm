/* https://programmers.co.kr/learn/courses/30/lessons/42883 */

#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	list<char> num;

	for (int i = 0; i < number.size(); i++)
		num.push_back(number[i]);

	int cnt = 0;

	auto iter1 = num.begin();
	auto iter2 = ++num.begin();

	while (cnt != k) {
		while (iter2 != num.end()) {

			if (*iter1 < *iter2) {
				iter1 = num.erase(iter1);
				iter2 = ++iter1;
				--iter1;
				cnt++;

				if (iter1 != num.begin()) {
					iter1--;
					iter2--;
				}
				break;
			}

			iter1++;
			iter2++;

			if (iter2 == num.end())	{
				for( ;cnt < k; cnt++)
                    num.pop_back();
				break;
			}
		}
	}

	for (auto iter = num.begin(); iter != num.end(); iter++)
		answer.push_back(*iter);

	return answer;
}