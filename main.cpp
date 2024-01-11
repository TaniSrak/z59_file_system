#include <iostream>
#include <string>
#include <fstream> // для работы с файловой системой

bool statistic(std::string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	std::string path = "File.txt";

	// класс ofstream для записи в файл
	
	std::ofstream out; //создали файл для записи данных в него
	out.open(path, std::ios::app); //open - метод объекта который открывает файл, передаем ему путь файла, который хотим открыть - ()
	//создает файл если его не существует

	if (out.is_open()) //проверка открытия файла
	{
		std::cout << "Файл открыт для записи\n";
		std::string str; //запись в файл информации
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << '\n';
	}
	else
	{
		std::cout << "Ошибка открытия файла\n";
	}
	out.close(); //закрытие файла, d () ничего не передается
	
	// класс ifstream для чтения из файла
	
	std::ifstream in;
	in.open(path);

	if (in.is_open())
	{
		std::cout << "Файл открыт. Содержимое файла:\n";
		std::string file;

		// посимвольное считывание
		//char sym;
		//while (in.get(sym))
		//{
		//	file += sym;
		//}
		//std::cout << file << std::endl;

		// пословное считывание
		//while (!in.eof()) //метод возвращает тру если курсор находится в конце файла
		//{
			//std::string word;
			//in >> word;
			//file += word + '\n';
		//}
		//std::cout << file << std::endl;

		//построчное считывание
		std::string str;
		while (std::getline(in, str))
		{
			file += str + '\n';

		}
		std::cout << file;
	}
	else
	{
		std::cout << "Ошибка открытия файла\n";
	}

	in.close();
	
	//удаление файла
	 
	// remove(path.c_str()); // неудобно

	if (remove(path.c_str()) == 0) //c_str преобразует из плюсов в обычный с язык
	{
		std::cout << "Файл удален\n";
	}
	else
	{
		std::cout << "Ошибка удаления файла\n";
	}
	

	//Task1 Статистика в файл
	std::cout << "ВВедите строку ->";
	std::string str1;
	std::getline(std::cin, str1);
	
	if (statistic(str1))
		std::cout << "Запись добавленаю\n";
	else
		std::cout << "Ошибка добавления записи\n";


	return 0;
}

// Task1 статистика в файл
bool statistic(std::string str)
{
	static std::ofstream out; //статик используется чтобы объект открывался для всей функции
	out.open("stats.txt", std::ios::app); //ios::app для того чтобы добавлялись записи файлов, а не перезаписывались постоянно

	if (out.is_open())
	{
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	return false;
}


