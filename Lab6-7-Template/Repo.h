#pragma once
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

template <class T> class Repo {
protected:
	vector<T> items;
public:
	Repo();
	~Repo();
	void Add(T item);
	void Delete(int poz, T item);
	void Update(int poz, T item);

	vector<T> getAll();
	int getSize();

	int getPoz(T item);
};

template <class T> Repo<T>::Repo() {

}

template <class T> Repo<T>::~Repo() {
	this->items.clear();
}

template <class T> void Repo<T>::Add(T item) {
	this->items.push_back(item);
}

template <class T> void Repo<T>::Delete(int poz, T item) {
	typename vector<T>::iterator it;

	it = find(this->items.begin(), this->items.end(), item);
	if (!(it == this->items.end()))
	{
		this->items.erase(it);
	}
}

template <class T> void Repo<T>::Update(int poz, T item) {
	this->items[poz] = item;
}

template <class T> vector<T> Repo<T>::getAll(){
	return this->items;
}

template <class T> int Repo<T>::getSize() {
	return this->items.size();
}

template <class T> int Repo<T>::getPoz(T item) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i] == item) {
			return i;
		}
	}
	return -1;
}