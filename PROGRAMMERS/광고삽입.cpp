/* https://programmers.co.kr/learn/courses/30/lessons/72414 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long t[360000];

int str_to_second(string str) {

    int t = 0;
    t += stoi(str.substr(0, 2)) * 60 * 60;
    t += stoi(str.substr(3, 2)) * 60;
    t += stoi(str.substr(6, 2));
    return t;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    long long sum = 0;
    int range = str_to_second(adv_time);

    for (auto s : logs) {
        int start = str_to_second(s.substr(0, 8));
        int end = str_to_second(s.substr(9, 8));
        t[start]++;
        t[end]--;
    }

    for (int i = 1; i < str_to_second(play_time); i++) 
        t[i] += t[i - 1];
    for (int i = 0; i < range; i++) 
        sum += t[i];

    long long max_sum = sum;
    long long start_time = 0;

    for (int i = range ; i < str_to_second(play_time); i++) {
        sum += t[i] - t[i - range];
        if (max_sum < sum) {
            max_sum = sum;
            start_time = i - range + 1;
        }
    }

    int s = start_time % 60;
    start_time /= 60;
    int m = start_time % 60;
    start_time /= 60;
    int h = start_time % 99;

    if (h < 10) 
        answer.push_back('0');
    answer+=to_string(h);
    answer.push_back(':');
    if (m < 10) 
        answer.push_back('0');
    answer+= to_string(m);
    answer.push_back(':');
    if (s < 10) 
        answer.push_back('0');
    answer+=to_string(s);
    return answer;
}