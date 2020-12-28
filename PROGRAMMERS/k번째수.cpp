/* https://programmers.co.kr/learn/courses/30/lessons/42748 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i,j,k;
    
    for(int a = 0 ; a < commands.size() ; a++){
        
        vector<int> temp(array);
        
        i = commands[a][0] -1 ;
        j = commands[a][1];
        k = commands[a][2];
        
        sort(temp.begin() + i,temp.begin()+j);
        answer.push_back(temp[i+k-1]);
    }
    
    return answer;
}