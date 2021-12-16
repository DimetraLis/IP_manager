#include "IP_manager.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*public*/





IP_man::IP_man(const string& _ip):ip(ip) {
	cout << "Конструктор IP" << endl;
}
IP_man::IP_man(const IP_man& g) :ip(g.ip) {
	cout << "Конструктор копирования IP" << endl;
}
IP_man::~IP_man() {
	cout << "Деструктор IP" << endl;
}
/*геттеры сеттеры*/
string& IP_man::_IP() { return ip; }

void IP_man::set_ip(string in_ip) {
	ip = in_ip;
}
//перегрука операторов ввода и выводадля объектов
istream& operator>>(std::istream& in, IP_man& g) {
	if (!(in >> g.ip)) cout << "reading exception" << endl;
	return in;
}
ostream& operator<<(std::ostream& out, const IP_man& g) {
	out << g.ip;
	return out;
}