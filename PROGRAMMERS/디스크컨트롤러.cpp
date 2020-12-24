/* https://programmers.co.kr/learn/courses/30/lessons/42627 */

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<vector<int>> jobs) {
    
    int answer = 0;
    
    multiset<pair<int,int>> min_heap;
    
    sort(jobs.begin(),jobs.end());
    
    int index = 0 ;
    int time = 0;
    int sum  = 0;
    
    while(1){
        
        if(min_heap.empty()) {
            if(index == jobs.size())
                break;
            
            time = jobs[index][0];

            int req_time = jobs[index][0];
            int take_time = jobs[index][1];
            
            min_heap.insert(make_pair(take_time,req_time));
            
            index++;
        }
        else {             
            time += min_heap.begin()->first; 
            sum += time - min_heap.begin()->second;
            min_heap.erase(min_heap.begin());
            
            for(;index < jobs.size() && time >= jobs[index][0];index++){ 
                min_heap.insert(make_pair(jobs[index][1],jobs[index][0]));
            }
        }       
    } 
    return sum/jobs.size();
}