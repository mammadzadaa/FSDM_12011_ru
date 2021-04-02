#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int sum(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int devide(int x, int y)
{
	if (y == 0)
	{
		throw;
	}
	return (x / y);
}

bool foo(int a, int b)
{
	return a > b;
}

template<typename T>
class functor
{
private:
	bool m_state;
public:
	functor(bool state) : m_state(state) {}
	bool operator()(T a, T b)
	{
		if (m_state)
		{
			return a > b;
		}
		return a < b;
	}
};

int main()
{
	int num = 1;
	int val = 9;
	[num](int n) ->void {	cout << "My num: " << n << endl;
					cout << "Calc App "  << "number " << num << ":\n"; 
				}(val);


	map<char, int(*)(int, int)> calc;
	calc['+'] = [](int a, int b)->int { return a + b; };
	calc['-'] = sub;
	calc['*'] = mul;
	calc['/'] = devide;

	int a, b;
	char c;
	cin >> a >> c >> b;
	cout << calc[c](a, b) << endl;

	cout << "/////////////////////\n";
	vector<int> vec = { 3,4,7,1,4,9,3 };
	sort(vec.begin(), vec.end(), [](int a, int b) ->bool {return a > b; });
	for (auto i : vec)
	{
		cout << i << endl;
	}
	cout << "/////////////////////\n";
	/*int a = 10;
	int b = 20;
	int c = 0;
	char* name = _strdup("Ibrahim");
	[name, c]() {cout << "Hello " << name << endl; }();
	[&c](int x, int y) {c = x + y; }(a, b);
	cout << c << endl;
	cout << "/////////////////////\n";
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), []() { static int a = 1; return a *= 2; });
	for (auto i : vec)
	{
		cout << i << endl;
	}
	sort(vec.begin(), vec.end(), functor<int>(true));
	functor<int>(true)(23, 34);*/
	system("pause");
	return 0;
}




//#include<iostream>
//#include<string>
//#include<list>
//
//#include<map>
//#include<set>
//#include<unordered_map>
//#include<unordered_set>
//
//#include<vector>
//
//#include<deque>
//
//#include<queue>
//#include<stack>
//
//#include<algorithm>
//#include<numeric>
//
//using namespace std;
//
//class point
//{
//private:
//	int x;
//	int y;
//public:
//	point(int a, int b) : x(a), y(b) {}
//};
//
//bool sort_check(int a, int b)
//{
//	return a > b;
//}
//
//template<typename T>
//void print(T begin, T end)
//{
//	for (T i = begin; i != end; i++)
//	{
//		cout << *i << endl;
//	}
//}
//class my_rand
//{
//private:
//	int m_min;
//	int m_max;
//public:
//	my_rand(int min, int max) : m_min(min), m_max(max) {}
//	int operator()()
//	{
//		return m_min + (rand() % (m_max - m_min));
//	}
//};
//
//class Check
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//
//int main()
//{
//	/*my_rand rand(10, 100);
//	cout << rand() << endl;*/
//	int arr[8];
//	generate(arr, arr + 8, my_rand(10, 100)); //my_rand(10,100)()
//	sort(arr, arr + 8, Check());
//	vector<int> a(8);
//	//vector<int>::iterator;
//	copy(arr, arr + 8, a.begin());
//	//list<int>::iterator;
//	list<int> b(8);
//	copy(a.begin(), a.end(), b.begin());
//	sort(a.begin(), a.end(), sort_check);
//	unique(a.begin(), a.end());
//	a.resize(7);
//	if (is_sorted(a.begin(), a.end(), sort_check))
//	{
//		print(a.begin(), a.end());
//		/*for (auto i : a)
//		{
//			cout << i << endl;
//		}*/
//	}
//	int j = 0;
//	cout << *min_element(a.begin(), a.end()) << endl;
//	cout << accumulate(b.begin(), b.end(), j);
//
//
//	/*vector<point> a;
//	a.emplace(a.begin(),34,45);
//	a.emplace_back(12,34);
//	deque<int> b;*/
//
//	/*unordered_map<int,string> a;
//	a.insert({43,"Behram"});*/
//
//	system("pause");
//	return 0;
//}



//#include<iostream>
//#include<set>
//#include<map>
//#include<string>
//
//using namespace std;
//
////bool func(int a, int b)
////{
////	return 1;
////}
////bool fun(int a, int b)
////{
////	return 0;
////}
////void foo(int a,int b, bool (*foo1)(int,int) )
////{
////	if (foo1(a, b))
////	{
////		cout << "ver 1\n";
////	}
////	else
////	{
////		cout << "ver 2\n";
////	}
////}
//
//
//int main()
//{
//	/*foo(12,34,fun);*/
//	set<int> a;
//	/*for (size_t i = 0; i < 5; i++)
//	{
//		a.insert(i*12);
//	}
//	for ( auto i = a.begin(); i != a.end(); i++)
//	{
//		cout << *i << endl;
//	}
//	cout << "////////////////////////\n";
//	cout << a.size() << endl << a.max_size() << endl;
//	if (!a.empty())
//	{
//	auto j = a.find(24);
//	cout << *++j << endl;
//	a.erase(j,a.end());
//	}
//	cout << "////////////////////////\n";
//	for (auto i = a.begin(); i != a.end(); i++)
//	{
//		cout << *i << endl;
//	}*/
//	multiset<int> b;
//	/*for (size_t i = 0; i < 5; i++)
//	{
//		b.insert(10 + rand()%100);
//	}
//	for (auto i = b.begin(); i != b.end(); i++)
//	{
//		cout << *i << endl;
//	}
//	auto j = b.begin();
//	b.insert(j, 20);
//	b.insert(++j, 20);
//	cout << "/////////////\n";
//	j = b.find(44);
//	cout << *--j << endl;
//	cout << *--j << endl;
//	cout << *--j << endl;
//	for (auto i = b.begin(); i != b.end(); i++)
//	{
//		cout << *i << endl;
//	}*/
//	map<int, string> c;
//	//c.insert(pair<int,string>(23,"Aftandil"));
//	//c.insert(pair<int, string>(15, "Israfil"));
//	//c.insert(pair<int, string>(43, "Behram"));
//	//for (auto i = c.begin(); i != c.end(); i++)
//	//{
//	//	cout << i->second << endl;
//	//}
//	//cout << "/////////////\n";
//	//cout << c.at(43) << endl;
//	//cout << "/////////////\n";
//	//map<int,string>::iterator j =  c.find(15);
//	//cout << (++j)->second << endl;
//	//cout << "/////////////\n";
//	//c.insert(pair<int,string>(23,"Eflatun"));
//	//for (auto i = c.begin(); i != c.end(); i++)
//	//{
//	//	cout << i->second << endl;
//	//}
//
//	multimap<int, string> d;	
//
//	d.insert(pair<int, string>(23, "Aftandil"));
//	d.insert(pair<int, string>(15, "Israfil"));
//	d.insert(pair<int, string>(43, "Behram"));
//	d.insert(pair<int, string>(23, "Elsever"));
//	for (auto i = d.begin(); i != d.end(); i++)
//	{
//		cout << i->second << endl;
//	}
//	auto k = d.find(25);
//	if (k != d.end())
//		cout << k->second << endl;
//	system("pause");
//	return 0;
//}
//
