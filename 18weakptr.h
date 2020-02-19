#pragma once
using namespace std;


template<class T>class Lweakptr;
template<class T>
class Yptr{
	friend class Lweakptr<T>;
	Ref<T>* ref = nullptr;
public:

	Yptr() = default;
	~Yptr(){
		if (ref){
			ref->reduce();
		}
	}
	Yptr(Ref* newRef){
		ref = newRef;
		if (ref){
			ref->increase();
		}
	}
	Yptr(T* newP){
		ref = new Ref<T>(newP);
	}
	Yptr(const Yptr& other){
		ref = other.ref;
		if (ref){
			ref->increase();
		}
	}
	Yptr(Yptr&& other){
		swap(ref, other.ref);
	}
	Yptr&& operator=(Yptr&& other){
		if (ref){
			ref->reduce;
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	Yptr&& operator=(Yptr& other){
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		if (ref){
			ref->increase();
		}
		return *this;
	}
	void swap(Yptr& other){
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr){
		if (ref){
			ref->reduce();
		}
		if (target != nullptr){
			ref = new Ref<T>(target);
		}
		else{
			ref = nullptr;
		}
	}
	T& operator*(){
		if (ref){
			return *ref->get();
		}
		else{
			return *(T*)nullptr;
		}
	}
	T* operator->(){
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	T* get(){
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	int use_count(){
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool unique(){
		if (ref){
			return ref->getCount() == 1;
		}
		else{
			return false;
		}
	}
	operator bool(){
		return ref != nullptr;
	}
};

template<class T>
class Ref{

	int count = 0;
	int w_count = 0;
	T* object = nullptr;

public:
	Ref(T* target) :object(target){
		++count;
	}
	inline void increase(){
		count++;
	}
	inline void increase_w(){
		w_count++;
	}

	inline void reduce(){
		count--;
		if (count == 0){
			delete object;
			object == nullptr;
			if (w_count == 0){
				delete this;
			}
		}
	}
	inline void reduce_w(){
		w_count--;
		if (w_count == 0 && count == 0){
			delete this;
		}
	}
	T* get(){
		return object;
	}
	int getCount(){
		return count;
	}
};
template<class T>class Lweakptr{
	Ref<T>* ref = nullptr;
public:
	Lweakptr() = default;
	Lweakptr(Yptr<T>& other) :ref(other.ref){
		if (ref){
			ref.increase_w();
		}
	}
	Lweakptr(const Lweakptr& other) :ref(other.ref){
		if (ref){
			ref.increase_w();
		}
	}
	Lweakptr(Lweakptr<T>&& other){
		swap(ref, other.ref);
	}
	Lweakptr<T>& operator=(const Lweakptr<T>& other){
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref){
			ref->increase_w();
		}
		return *;
	}
	Lweakptr<T>& operator=(Lweakptr<T>&& other){
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		if (ref){
			ref->increase_w();
		}
		return *this;
	}
	int use_count(){
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool expired(){
		if (ref){
			return ref->getCount()>0;
		}
		else{
			return false;
		}
	}
	Yptr<T> lock(){
		Yptr<T> tem(ref);
		return tem;
	}
	void swap(Lweakptr<T> other){
		swap(ref, other.ref);
	}
	void reset(){
		ref->reduce_w();
		ref = nullptr;
	}

};