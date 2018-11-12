#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string str1, str2, str3;
	long long a, b, c = 0;
	long long res = 0;
	map<string, pair<int, int> > m;

	m.insert({ "black",{ 0,1 } });
	m.insert({ "brown",{ 1,10 } });
	m.insert({ "red",{ 2,100 } });
	m.insert({ "orange",{ 3,1000 } });
	m.insert({ "yellow",{ 4,10000 } });
	m.insert({ "green",{ 5,100000 } });
	m.insert({ "blue",{ 6,1000000 } });
	m.insert({ "violet",{ 7,10000000 } });
	m.insert({ "grey",{ 8,100000000 } });
	m.insert({ "white",{ 9,1000000000 } });

	cin >> str1 >> str2 >> str3;

	a = m.find(str1)->second.first;
	b = m.find(str2)->second.first;
	c = m.find(str3)->second.second;

	res = (a * 10 + b) * c;
	cout << res;
}
