#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
using namespace std;

int main()
{
	//array<int, 10> a;
	//vector<int> b(10);
	
	vector<int> arr(5);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	cout << arr.at(2) << endl;
	cout << arr.size() << endl;
	
	deque<int> d;
	forward_list<int> fl;
	list<int> l;	
	

	return 0;
}