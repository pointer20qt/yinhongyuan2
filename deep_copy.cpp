#include<iostream>
#include<vector>
#include<string>
using namespace std;
class principal{
	string name;
public:
	principal(string sname){
		this->name = sname;
	}
	~principal(){
		cout << "����ʦ�°���" << endl;
	}
};

class school{
public:
	std::string schoolName;
	std::string schoolType;
	std::string address;
	principal* master;
	~school(){
		delete master;
	}
	//this���Զ�����ȥһ����������Ϊ ���г�Ա��������Ҫ��һ��thisָ��
	school(std::string schoolName, std::string schoolType, std::string address){
		this->schoolName = schoolName;
		this->address = address;
		this->schoolType = schoolType;
		master = new principal("����ʦ");
	}
	school(const school& p){
		cout << "�������캯��" << endl;
		master = new principal(*(p.master));
	}	
	
};

void swap(school A, school B){
	school tem = A;
	B.operator=(A);
	A = tem; 
}

void run(){
	school s1("����ʯ�ʹ�ѧ", "��ѧ", "����");
	school s2("��һũ�Ѵ�ѧ", "��ѧ", "����");
	swap(s1, s2);
}
int main2(){
	run();
	cout << "��һ�����" << endl;

	return 0;
}

