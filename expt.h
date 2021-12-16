#pragma once
#include <string>

class Exception {
	std::string message;//сообщение исклюения
public:
	//констурктор
	Exception(const std::string& message = "Exception");
	//констурктор копирования
	Exception(const Exception& e);
	//деструктор
	~Exception();
	const std::string& what()const;//выводим сообщение исключения
};