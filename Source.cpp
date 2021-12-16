#include "IP_manager.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int str_to_int(string in);
string is_correct();

int main(){
	setlocale(LC_ALL, "");
	IP_man ip_adr;
	Helper hp;
	ifstream in;
	ofstream out;
	string in_ip;
	int ch, n;
	bool flag = true;
	
	while (flag) {
		system("cls");
		cout << "1 - Add IP" << endl;
		cout << "2 - Change IP" << endl;
		cout << "3 - Delete IP" << endl;
		cout << "4 - Show IP" << endl;
		cout << "5 - Save IP" << endl;
		cout << "6 - Load IP" << endl;
		cout << "0 -Exit" << endl;

		cin >> ch;

		if (cin.fail()) {
			ch = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (ch) {
		case 1:		
			try{
				   cout << "Enter ip adress, please\n";
				   
				   in_ip=is_correct();

				  
				   cout << in_ip << endl;
				   ip_adr.set_ip(in_ip);


				   hp.IP().add(ip_adr);
				   
				   system("pause");
				   break;
	
			   }
			catch(const Exception& exc){//в случае ошшибки попадем сюда
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cin.clear();
			    cin.sync();
				cout << exc.what();
			}
			system("pause");
			break;
		case 2:
			try {
				cout << "Enter the index of IP to change data\n";
				while (!(cin >> ch) && ch >= 0 && ch < hp.IP().size());//проверка на индекс
				cout << "Enter new IP\n";
				in_ip = is_correct();
				hp.IP()[ch].set_ip(in_ip);//перезапись на место нынешнего - новый объект
				break;
				
			}
			catch (const Exception& exc) {//обработка ошибок
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				cin.sync();
				cout << exc.what();
			}
			system("pause");
			break;
		case 3:
			while (!(cin >> ch) && ch >= 0 && ch < hp.IP().size());//проверка на индекс
			hp.IP().remove(ch);//функция удаления
			break;
			system("pause");
		case 4:
			for (int i = 0; i < hp.IP().size(); ++i) {
				cout << i << " " << hp.IP()[i] << endl;
			}
			system("pause");
			break;

		case 5:
			out.open("IP_adresses");//открытие нужного файла для сохарнения 
			out << hp.IP().size() << '\n';//запись размера - количество объектов
			for (int i = 0; i < hp.IP().size(); ++i)//запись в файл
				out << hp.IP()[i]._IP() << '\n';
			system("pause");
			break;

		case 6:
			in.open("IP_adresses");//откртыие нужного фалйа
			in >> n;
			for (int i = 0; i < n; ++i) {//загрузка из фалйа
				in >> ip_adr;
				hp.IP().add(ip_adr);//функция добавления объекта
			}
			system("pause");
			break;


		case 0:
			flag = false;
			break;

			system("pause");
			return 0;
		}
	}
}

int str_to_int(string in) {
	string tmp = "";  // временная строка
	for (int i = 0; i < in.length(); i++) { // прохождение по строке до конца
		if (isdigit(in[i])) { // проверка текущего символа - цифра ли это
			tmp += in[i]; // если да - запись во временную строку
		}
		else {
			return -1; // если нет - выводим -1, который находится вне диапазона в дальнейшем
		}
	}
	return stoi(tmp);
}


string is_correct() { // проверка одного IP
	string IP, save;
	bool flag = true;
	bool w_flag = true;
	int cnt = 1; // счетчик элементов в адрессе
	int pos, curr_num; // позиция в строке, текущий элемент 
	string token; // текущий токен
	while (w_flag) {
		flag = true;
		cout << "Enter IP adress: ";
		cin >> IP;
		save = IP;
		while ((pos = IP.find('.')) != std::string::npos) {//поиск по точкам до конца
			token = IP.substr(0, pos); //взятие токена

			curr_num = str_to_int(token);//преобразовать в int

			if (!(curr_num >= 0 && curr_num <= 255)) { flag = false; break; };//проверка, на диапазон числа

			IP.erase(0, pos + 1); // стереть до точки
			cnt++;
		}
		if (cnt == 4 && flag == true) { w_flag = false; return save; }
		

	}
}