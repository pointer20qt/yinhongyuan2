#include<iostream>
#include<vector>
using namespace std;

template<class T>class L_stack{
	std::vector<T>arr;
public:
	void push(T&& obj){
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size(){
		return arr.size();
	}
};

template<class T, class...args>void Lprint(T f, args...d){
	cout << f << endl;
	Lprint(d...);
}
void Lprint(){
	cout << "µÝ¹é½áÊø" << endl;
}

int main3(){
	Lprint(2, 3, 53, 5, 7, 9);
	L_stack<int> lc;
	lc.push(5);
	cout << lc.top() << endl;

	return 0;
}