#include <iostream>
#include <string>
#include <vector>

using namespace std;

//游泳馆
//虚基类
class Natatorlum
{
public:
	virtual void wash() = 0;
};

class principal :public Natatorlum
{
	string name;
public:
	principal(string sname)
	{
		this->name = sname;
	}
	~principal()
	{

	}
	void wash()
	{
		cout << "洗浴" << endl;
	}
};

class school :public Natatorlum
{
private:
	std::string schoolName;
	std::string schoolType;
	std::string address;
public:
	std::string getSchoolName()
	{ 
		return schoolName;
	}
	principal * master;
	school(std::string schoolName,std::string schoolType,std::string address)
	{
		cout << "普通构造函数" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("杨老师");
	}
	virtual ~school()
	{
		cout << schoolName << "闭校了" << endl;
		delete master;
	}	
	school(const school& p) :schoolType(p.schoolType), address(p.address)
	{
		schoolName = p.schoolName;
		cout << this->schoolName << "拷贝建立了" << endl;
		master = new principal(*(p.master));
	}
	//类默认的移动构造,和默认的拷贝构造效果
	school(school&& other) :schoolType(other.schoolType), schoolName(other.schoolName), address(other.address)
	{
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
	//开学
	virtual void schoolOpens()
	{
		cout << this->schoolName << "开学了" << endl;
	}
	
};

vector<Natatorlum*> allWash;

//继承会将所有的成员继承
class University :public school
{
public:
	//副校长
	principal* Vice;
	University() :school("大庆指针", "软件培训", "大庆")
	{
		cout << "大学的构造函数" << endl;
		Vice = new principal("尹弘远");
	}
	virtual void schoolOpens()
	{
			cout << "在大学校长的带领下" << getSchoolName() << "开学典礼结束了" << endl;
	}
	~University()
	{
		cout << "调用到大学的析构函数" << endl;
		delete Vice;
	}
};

class highSchool :public school
{
public:
	highSchool() :school("宾县一中", "高中", "宾县")
	{
		cout << "高中的构造函数" << endl;
	}
};
void printfSchool(school* school)
{
	school->schoolOpens();
	delete school;
}
void printfSchool(school& school)
{
	school.schoolOpens();
	delete &school;
}
class A
{
public:
	virtual void fun()
	{
		cout << "A的fun" << endl;
	}
	virtual void druck()
	{
		cout << "A的druck" << endl;
	}
};
class B :public A
{
	virtual void fun()
	{
		cout << "B的fun" << endl;
	}
};
int main()
{
	A a;
	B b;
	A* pb = &b;
	pb->druck();
	pb->fun();

	return 0; 
}