#pragma once
#include <string>

template<typename T>
struct item {//элемент списка
	T _data; // значенеи элемента
	item* _next;	//ссылка на следущий элемент
	item* _prev;	//ссылка на предыдущий элемент
};

template<typename T>
class Keeper {
private:
	item<T>* _head; //начало списка
	item<T>* _tail; //начало списка
	int _size; //размер
public:
	Keeper();//конструктор
	void add(const T& _data);//заносим элемент в конец списка
	T remove(int index);//удаляем i-ый элемент
	int size(); //размер
	T operator[](int index)const;//получение i-го элемента
	T& operator[](int index);//получение i-го элемента
	void clear();
	~Keeper(); //деструктор
};

template<typename T>
void Keeper<T>::clear() {
	for (int i = 0; i < _size; --_size) {//проходим по каждому элементу
		item<T>* buf = _head;
		_head = _head->_next;//переходим к следующему
		delete buf;//удаляем предыдущий
	}
}

template<typename T>
Keeper<T>::Keeper<T>() : _head(nullptr), _tail(nullptr), _size(0) {
}




template<typename T>
void Keeper<T>::add(const T& _data) {
	item<T>* buf = new item<T>;
	buf->_data = _data;
	buf->_next = nullptr;
	buf->_prev = _tail;
	if (_tail) {
		_tail->_next = buf;
	}
	if (_head == nullptr) {
		_head = buf;
	}
	_tail = buf;
	++_size;
}

template<typename T>
T Keeper<T>::remove(int index) {
	if (index < 0 || index >= _size) {//если неверный  индекс
		return T(0);
	}
	item<T>* temp = _head;
	for (int i = 0; i < _size && i < index; ++i) {	// получаем нужный элемент
		temp = temp->_next;
	}

	if (temp == nullptr) {// если не нашли
		return T(0);
	}
	if (temp->_prev) {
		temp->_prev->_next = temp->_next;
	}
	if (temp->_next) {
		temp->_next->_prev = temp->_prev;
	}
	T _data = temp->_data;

	if (temp->_prev == nullptr) {
		_head = temp->_next;
	}
	if (temp->_next == nullptr) {
		_tail = temp->_prev;
	}
	delete temp;
	--_size;
	return _data;
}

template<typename T>
int Keeper<T>::size() {
	return _size;
}

template<typename T>
T& Keeper<T>::operator[](int index) {
	item<T>* buf = _head;
	for (int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
		buf = buf->_next;
	}
	return buf->_data;
}

template<typename T>
T Keeper<T>::operator[](int index)const {
	item<T>* buf = _head;
	for (int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
		buf = buf->_next;
	}
	return buf->_data;
}

template<typename T>
Keeper<T>::~Keeper() { //деструктор
	for (int i = 0; i < _size; --_size) {//проходим по каждому элементу
		item<T>* buf = _head;
		_head = _head->_next;//переходим к следующему
		delete buf;//удаляем предыдущий
	}
}
