#include "expt.h"
#include <iostream>
using namespace std;

Exception::Exception(const std::string& message) :message(message) {
	cout << "����������� ������" << endl;
}
Exception::Exception(const Exception& e) : message(e.message) {
	cout << "����������� ����������� ������" << endl;
}
Exception::~Exception() {
	cout << "���������� ������" << endl;
}
const std::string& Exception::what()const {
	return message; //�� ����� ��������� �������, ��� ����������
}