#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//��ôͨ��rand����[0,a)����
//��ôͨ��rand����[a,b)����
//��ô����һ��0~1�����С��double
//��ô����a~b�����С��
//����0��100���������������жϳɹ�,�ɹ�����true
//����0��1��double���������жϳɹ����ɹ�����ture��

//rand()�������������ȡ��һ��    srand(time(0)) ��ʼ�����������

void Y_double()
{
	srand(time(0));
	for (int i = 0; i < 10;i++)
	{
		cout << (rand() / (double)RAND_MAX) *10<< endl;
	}
}

bool Y_int(int a,int b,int c)
{
	srand(time(0));	
	int d = (rand() % (b - a)) + a;
	if ( d>c)
	{
		cout << "���ĺ�����:"<< d <<endl <<"�н���!������!" << endl;
		return true;
	}
	else
	{
		cout << "���ĺ�����:" << d << endl << "û�н�!�ܲ���!" << endl;
		return false;
	}

}

int main()
{
	int a = 10;
	int b = 20;
	int c = 18;
	Y_int(a,b,c);
	Y_double();
	return 0;
}