#include <iostream>
#include <string>
#include <vector>

using namespace std;

//��Ӿ��
//�����
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
		cout << "ϴԡ" << endl;
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
		cout << "��ͨ���캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}
	virtual ~school()
	{
		cout << schoolName << "��У��" << endl;
		delete master;
	}	
	school(const school& p) :schoolType(p.schoolType), address(p.address)
	{
		schoolName = p.schoolName;
		cout << this->schoolName << "����������" << endl;
		master = new principal(*(p.master));
	}
	//��Ĭ�ϵ��ƶ�����,��Ĭ�ϵĿ�������Ч��
	school(school&& other) :schoolType(other.schoolType), schoolName(other.schoolName), address(other.address)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
	//��ѧ
	virtual void schoolOpens()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}
	
};

vector<Natatorlum*> allWash;

//�̳лὫ���еĳ�Ա�̳�
class University :public school
{
public:
	//��У��
	principal* Vice;
	University() :school("����ָ��", "�����ѵ", "����")
	{
		cout << "��ѧ�Ĺ��캯��" << endl;
		Vice = new principal("����Զ");
	}
	virtual void schoolOpens()
	{
			cout << "�ڴ�ѧУ���Ĵ�����" << getSchoolName() << "��ѧ���������" << endl;
	}
	~University()
	{
		cout << "���õ���ѧ����������" << endl;
		delete Vice;
	}
};

class highSchool :public school
{
public:
	highSchool() :school("����һ��", "����", "����")
	{
		cout << "���еĹ��캯��" << endl;
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
		cout << "A��fun" << endl;
	}
	virtual void druck()
	{
		cout << "A��druck" << endl;
	}
};
class B :public A
{
	virtual void fun()
	{
		cout << "B��fun" << endl;
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