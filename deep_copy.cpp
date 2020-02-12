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
		cout << "杨老师下班了" << endl;
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
	//this是自动传进去一个参数，因为 所有成员方法都需要传一个this指针
	school(std::string schoolName, std::string schoolType, std::string address){
		this->schoolName = schoolName;
		this->address = address;
		this->schoolType = schoolType;
		master = new principal("杨老师");
	}
	school(const school& p){
		cout << "拷贝构造函数" << endl;
		master = new principal(*(p.master));
	}	
	
};

void swap(school A, school B){
	school tem = A;
	B.operator=(A);
	A = tem; 
}

void run(){
	school s1("东北石油大学", "大学", "大庆");
	school s2("八一农垦大学", "大学", "大庆");
	swap(s1, s2);
}
int main2(){
	run();
	cout << "下一句代码" << endl;

	return 0;
}

