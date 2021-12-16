#pragma once
#include <string>

template<typename T>
struct item {//������� ������
	T _data; // �������� ��������
	item* _next;	//������ �� �������� �������
	item* _prev;	//������ �� ���������� �������
};

template<typename T>
class Keeper {
private:
	item<T>* _head; //������ ������
	item<T>* _tail; //������ ������
	int _size; //������
public:
	Keeper();//�����������
	void add(const T& _data);//������� ������� � ����� ������
	T remove(int index);//������� i-�� �������
	int size(); //������
	T operator[](int index)const;//��������� i-�� ��������
	T& operator[](int index);//��������� i-�� ��������
	void clear();
	~Keeper(); //����������
};

template<typename T>
void Keeper<T>::clear() {
	for (int i = 0; i < _size; --_size) {//�������� �� ������� ��������
		item<T>* buf = _head;
		_head = _head->_next;//��������� � ����������
		delete buf;//������� ����������
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
	if (index < 0 || index >= _size) {//���� ��������  ������
		return T(0);
	}
	item<T>* temp = _head;
	for (int i = 0; i < _size && i < index; ++i) {	// �������� ������ �������
		temp = temp->_next;
	}

	if (temp == nullptr) {// ���� �� �����
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
	for (int i = 0; i < _size && i < index; ++i) { //���� ������ �������
		buf = buf->_next;
	}
	return buf->_data;
}

template<typename T>
T Keeper<T>::operator[](int index)const {
	item<T>* buf = _head;
	for (int i = 0; i < _size && i < index; ++i) { //���� ������ �������
		buf = buf->_next;
	}
	return buf->_data;
}

template<typename T>
Keeper<T>::~Keeper() { //����������
	for (int i = 0; i < _size; --_size) {//�������� �� ������� ��������
		item<T>* buf = _head;
		_head = _head->_next;//��������� � ����������
		delete buf;//������� ����������
	}
}
