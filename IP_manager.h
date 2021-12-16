#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class IP_man {
protected:
	string ip;
public:
	//конструктор
	IP_man(const string& IP = "");
	//конструктор копирования
	IP_man(const IP_man& g);


	 ~IP_man();
	/*геттеры сеттеры - функции получения и установления значений*/
	string& _IP();
	void set_ip(string in_ip);
	
	friend std::istream& operator>>(std::istream& in, IP_man& g);
	friend std::ostream& operator<<(std::ostream& out, const IP_man& g);
};