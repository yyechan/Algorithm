#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int Min = 99999;

void broke(vector<vector<int>>& map, int x, int y)
{
	int range = map[y][x] - 1;

	map[y][x] = 0;

	for (int x_range = x - range; x_range <= x + range; x_range++) {


		if (0 <= x_range && x_range < map[0].size()) {
			if (map[y][x_range] == 1)
				map[y][x_range] = 0;
			else if (map[y][x_range] != 0)
				broke(map, x_range, y);
		}

	}

	for (int y_range = y - range; y_range <= y + range; y_range++)	{

		if (0 <= y_range && y_range < map.size()) {
			if (map[y_range][x] == 1)
				map[y_range][x] = 0;			
			else if (map[y_range][x] != 0)

				broke(map, x, y_range);
		}

	}




}

int getY(vector<vector<int>> &map ,int x) {
	int Y = -1;


	for (int i = 0; i < map.size(); i++) {

		if (map[i][x] != 0) {
			Y = i;
			break;
		}
	}
	return Y;
}

void setMap(vector<vector<int>>& map) {

	int sum = 0;

	for (int x = 0;x< map[0].size(); x++) {

		vector<int> temp;
		int zero_count = 0;

		for (int y = map.size()-1; y>=0; y--) {
			if (map[y][x] != 0)	{
				temp.push_back(map[y][x]);
				sum++;
			}
			
		}

		for (int y = 0; y < map.size(); y++) {
			map[y][x] = 0;
		}

		int y = map.size() - 1;

		for (int i = 0; i < temp.size() ;i++) {
			map[y][x] = temp[i];
			y--;
		}


	}

	if (sum == 0){
		Min = 0;
	}

}

void dfs(vector<vector<int>> &map ,int depth,int N) {
	if (depth == N)	{
		int Count = 0;

		for(int y = 0 ; y<map.size();y++)
			for (int x = 0; x < map[0].size(); x++)	{

				if (map[y][x] != 0)
					Count++;
			}

		Min = min(Min, Count);
		return;
	}	
		for (int x = 0; x < map[0].size(); x++)	{

			int y = getY(map, x);

			if (y != -1) {	
				
				if (map[y][x] != 0)	{
					vector<vector<int>> temp = map;
					broke(temp, x, y);
					setMap(temp);
					dfs(temp, depth + 1, N);
					temp = map;
				}
			}

		}
}


int main()
{

	int TestCase;

	cin >> TestCase;

	vector<vector<vector<int>>> map(TestCase);
	vector<int> answer;

	for (int i = 0; i < TestCase; i++) {
		int N, W, H;
		Min = 99999; 
		cin >> N >> W >> H;
		for (int y = 0; y < H; y++)	{
			map[i].push_back(vector<int>());
			for (int x = 0; x < W; x++)	{				
                int input;
				cin >> input;
				map[i][y].push_back(input);
			}
		}
		dfs(map[i], 0, N);
		answer.push_back(Min);
		////////// 데이터 입력
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << "#" << i + 1 << " ";
		cout << answer[i] << "\n";
	}
}