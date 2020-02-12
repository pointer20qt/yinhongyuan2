#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int a[4] = {1,2,3,4};
	vector<int>arr{1, 2, 3, 4};
	try
	{
		for (int i = 0; i < 5; i++)
		{
			cout << arr.at(i) << endl;
		}
	}
	catch (out_of_range &e)
	{
		cout << "出现数组越界异常" << endl;
	}
	catch (...)
	{
		cout << "出现错误" << endl;
	}

	cout << "程序最后一句" << endl;
	return 0;
}