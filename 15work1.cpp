#include<iostream>

using namespace std;

class A{
public:
	int value = 0;
	char* p;
	A(int v){
		p = new char[100];
		value = v;
	}
	operator int(){
		cout << "��������ת��Ϊint" << endl;
		return value;
	}
	A(const A& other) :A(other.value){
		p = new char[100];
		value = other.value;
		cout << "��������" << endl;
	}
	A& operator=(const A& other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A(){
		delete p;
		cout << "�ж����������Ƿ�ִ��" << endl;
	}
};
template<class T>void Cswap(T&a, T&b){
	T temp = a;
	a = b;
	b = temp;
}
template<typename T> T comparemax(T a, T b){
	cout << "ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}
int comparemax(int a, int b){
	cout << "int�汾����" << endl;
	return a > b ? a : b;
}

int main(){
	int x = 1, y = 2;
	double c = 3.6, d = 4.7;
	cout << comparemax<>(x, y) << endl;
	cout << comparemax(c, d) << endl;
	A a(3), b(7);
	Cswap(a, b);
	Cswap(x, y);
	cout << "aֵ:" << a;
	cout << "bֵ��" << b;

}