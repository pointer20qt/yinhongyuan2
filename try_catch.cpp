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
		cout << "��������Խ���쳣" << endl;
	}
	catch (...)
	{
		cout << "���ִ���" << endl;
	}

	cout << "�������һ��" << endl;
	return 0;
}