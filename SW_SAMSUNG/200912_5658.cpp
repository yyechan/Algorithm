#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


int main()
{

	int TestCase;

	cin >> TestCase;

	vector<string> answer(TestCase);

	for (int i = 0; i < TestCase; i++)
	{
		int N, K;
		set<string,greater<string>> Infos;
		string temp;
		cin >> N >> K;
		cin >> temp;
		int size = N / 4;

		for (int x = 0; x < size; x++)
		{
			int start_index = 0;

			for (int k = 0; k < 4; start_index += size ,k++)
			{
				string t = temp.substr(start_index, size);

				Infos.insert(t);
			}

			temp.insert(temp.begin(), temp.back());
			temp.pop_back();
			
		}

		set<string>::iterator iter = Infos.begin();

		for (int index = 0; index < K-1; index++)
		{
			iter++;
		}
		answer[i] = *iter;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << "#" << i + 1 << " ";
		cout << (int)strtol(answer[i].c_str(), NULL, 16);
		cout << "\n";

	}


}