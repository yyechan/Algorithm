#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> vec;

	for (int i : numbers) {
		vec.push_back(to_string(i));
	}

	sort(vec.begin(),vec.end(), [](string a, string b) -> bool { 
		string str1 = a + b;
		string str2 = b + a;
		return str1 > str2; 
        }
	);

	for (string temp : vec) {
		answer += temp;
	}

	if (answer[0] == '0') {
		return "0";
	}

	return answer;
}