#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//怎么通过rand生成[0,a)的数
//怎么通过rand生成[a,b)的数
//怎么生成一个0~1的随机小数double
//怎么生成a~b的随机小数
//传入0到100的整数，概率性判断成功,成功返回true
//传入0到1的double，概率性判断成功，成功返回ture。

//rand()从随机数序列中取下一个    srand(time(0)) 初始化随机数序列

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
		cout << "您的号码是:"<< d <<endl <<"中奖了!真幸运!" << endl;
		return true;
	}
	else
	{
		cout << "您的号码是:" << d << endl << "没中奖!很不幸!" << endl;
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