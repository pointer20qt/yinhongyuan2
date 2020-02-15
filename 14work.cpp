#include<iostream>
#include<Initializer_List>
#include<string>
#include<assert.h>

using namespace::std;
class vec{
private:
	int* obj;
public:
	vec(initializer_list<int> arr)
	{
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++){
			obj[i] = *(arr.begin() + i);
		}
	}
	int& operator[](unsigned int num){
		assert(num >= 0 && num <= 3);
		return obj[num];
	}
};

int main(){
	vec c{ 1, 2, 3, 4, 5 };
	cout << c[3] << endl;
	c[4] = 6;
	cout << c[4] << endl;

}