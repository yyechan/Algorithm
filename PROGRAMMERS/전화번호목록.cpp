#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool solution(vector<string> phone_book) {
    
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++)	{
		if (!strncmp(phone_book[i].c_str(), phone_book[i + 1].c_str(), phone_book[i].size())) {
			answer = false;
			return answer;
		}
	}

	return answer;
}
