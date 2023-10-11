#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string str;
	string explosive;
	cin >> str >> explosive;
	string tmpStr = "";

	for (int i = 0; i < (int)str.size(); i++)
	{
		tmpStr.push_back(str[i]);
		if (tmpStr.size() >= explosive.size())
		{
			if (tmpStr.compare(tmpStr.size() - explosive.size(), explosive.size(), explosive) == 0)
				tmpStr.erase(tmpStr.size() - explosive.size());
		}
	}
	cout << (tmpStr.empty() ? "FRULA" : tmpStr) << endl;
	return 0;
}