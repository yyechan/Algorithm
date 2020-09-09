#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




void norm(vector<int>& num) {

	num.push_back(0);

	for (int i = 0; i < num.size() - 1; i++) {


		if (num[i] < 0) { // 카라츠바에서 뺄셈이 존재함 
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back(); //뺄셈으로 인해 0이 된 자리수 제거 


	
}

//곱셈 구현
vector<int> mul(const vector<int>& a,const vector<int>& b) {

	vector<int> c(a.size() + b.size() + 1, 0);

	for(int i = 0 ; i < a.size() ; i++)
		for (int j = 0; j < b.size(); j++) {

			c[i + j] += a[i] * b[j];

		}

	norm(c);

	return c;
}


//더하기 구현 
void add(vector<int>& a,const vector<int>& b, int k) {

	vector<int> c;

	for (int i = 0; i < k; i++) {
		c.push_back(0);
	}

	for (int i = 0; i < b.size(); i++) {
		c.push_back(b[i]);
	}

	if (a.size() >= c.size()) {

		for (int i = 0; i < c.size(); i++) {
			a[i] += c[i];
		}

	}
	else
	{
		while (a.size() != c.size()) a.push_back(0);

		for (int i = 0; i < a.size(); i++) {
			a[i] += c[i];
		}

	}

	norm(a);

}

//빼기 구현

void sub(vector<int>& a, vector<int>& b) {

	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}

	norm(a);

}

vector<int> karatsuba(vector<int>& a, vector<int>& b) {

	int asize = a.size(), bsize = b.size();

	if (asize < bsize)	return karatsuba(b, a);

	if (asize == 0 || bsize == 0) return vector<int>();

	if (asize <= 50) return mul(a, b);



	int half = asize / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min((int)b.size(), half));
	vector<int> b1(b.begin() + min((int)b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	add(a0, a1, 0);
	add(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);

	sub(z1, z0);
	sub(z1, z2);

	vector<int> ret;

	add(ret, z2, 2 * half);
	add(ret, z1, half);
	add(ret, z0,0);


	return ret;




}




int main() {
	


	vector<int> a = { 4,3,2,1 };
	vector<int> b = { 8,7,6,5 };
	
	vector<int> vec = karatsuba(a, b);

	for (auto iter = vec.rbegin(); iter != vec.rend(); iter++) {

		cout << *iter;
	}

	return 1;



}
