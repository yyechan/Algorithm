#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	sort(participant.begin(),participant.end());
	sort(completion.begin(), completion.end());

	completion.push_back("dummy");

	for (int i = 0; i < participant.size(); i++) {

		if (participant[i].compare(completion[i])) {
			answer = participant[i];
			break;
		}
	}
    return answer;
}
