/* https://programmers.co.kr/learn/courses/30/lessons/42839 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[10000001];
bool visit[10];
int answer;


void DFS(string number, int depth, int n) {

    if (arr[n] == false) {
	    arr[n] = true;
	    answer++;
	}

	for (int i = 0; i < number.size(); i++)	{
		if (!visit[i]) {
			n *= 10;
			n += number[i] - '0';
			visit[i] = true;
			DFS(number, depth + 1, n);
			n /= 10;
			visit[i] = false;
		}
	}
}

int solution(string numbers) {

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i <= sqrt(10000000); i++) {

		if (arr[i] == true) // 이미 체크된 수의 배수는 확인하지 않는다
			continue;

		for (int j = i + i; j <= 10000000; j += i) { // i를 제외한 i의 배수들은 0으로 체크
			arr[j] = true;
		}
	}

	DFS(numbers, 0, 0);

	return answer;
}