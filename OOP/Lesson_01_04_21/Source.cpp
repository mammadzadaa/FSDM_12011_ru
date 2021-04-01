#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
#include<iostream>
using namespace std;

bool big_small(int a, int b)
{
	return a > b ? 1 : 0;
}
bool small_big(int a, int b)
{
	return a < b ? 1 : 0;
}
bool abs_big_small(int a, int b)
{
	return abs(a) > abs(b) ? 1 : 0;
}

int main()
{
	vector<int> a;
	a.reserve(10);
	a.push_back(34);
	a.push_back(24);
	a.push_back(37);
	a.push_back(13);
	a.push_back(67);
	a.shrink_to_fit();
	a.size();
	a.capacity();
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	cout << a.at(3) << endl;
	a.assign({ 1,2,34,45,65,3 });
	if (!a.empty())
	{
		a.clear();
	}
	cout << "//////////////////////////\n";
	
	list<int> b;
	auto z = b.begin();
	b.assign({ 34,-54,12,34,3,-21,34,-1,5,3,5 });
	b.sort(abs_big_small);
	b.unique();

	//for (/*list<int>::iterator*/auto i = b.begin(); i != b.end() ;i++)
	for (auto i : b)
	{
		cout << i << endl;
	}
	cout << "//////////////////////////\n";
	for (auto i = b.rbegin(); i != b.rend(); i++)
	{
		cout << *i << endl;
	}



	system("pause");
	return 0;
}
