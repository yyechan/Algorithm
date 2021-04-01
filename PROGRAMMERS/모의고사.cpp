/* https://programmers.co.kr/learn/courses/30/lessons/42840 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int p1_count = 0;
    int p2_count = 0;
    int p3_count = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == p1[i % p1.size()])
            p1_count++;
        if (answers[i] == p2[i % p2.size()])
            p2_count++;
        if (answers[i] == p3[i % p3.size()])
            p3_count++;
    }
    vector<int> temp;

    temp.push_back(p1_count);
    temp.push_back(p2_count);
    temp.push_back(p3_count);
    sort(temp.rbegin(), temp.rend());
    int max = temp[0];
    if (p1_count == max)
        answer.push_back(1);
    if (p2_count == max)
        answer.push_back(2);
    if (p3_count == max)
        answer.push_back(3);

    return answer;
}