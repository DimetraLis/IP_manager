#include "expt.h"
#include <iostream>
using namespace std;

Exception::Exception(const std::string& message) :message(message) {
	cout << "Конструктор Ошибки" << endl;
}
Exception::Exception(const Exception& e) : message(e.message) {
	cout << "Конструктор копирования Ошибки" << endl;
}
Exception::~Exception() {
	cout << "Детсруктор Ошибки" << endl;
}
const std::string& Exception::what()const {
	return message; //на экрна сообщение выведет, что передалось
}