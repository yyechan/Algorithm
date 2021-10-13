/* https://programmers.co.kr/learn/courses/30/lessons/42885 */

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(),people.end());
    
	deque<int> deq(people.begin(), people.end());
    
    while(!deq.empty()){
            
        if(deq.size() ==1){
            answer++;
            break;
        }
            if(deq[0] + deq[deq.size()-1]<=limit) {
                deq.erase(deq.begin());
               deq.pop_back();
                answer++;
            }
            else{   
                deq.pop_back();
                answer++;
            }
    }
    return answer;
}