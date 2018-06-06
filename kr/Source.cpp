#include <locale.h>
#include "Student.h"
#include <iostream>
#include "Group.h"
#include "Faculty.h"
#include <Windows.h>
void main()
{
	//setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Faculty *faculty = new Faculty();
	while (true)
	{
		int select;
		std::cout << "1)Добавить группу или студента.\n2)Удалить группу или студента.\n3)Поиск.\n4)Вывод.\n5)Сохранить в файл.\n6)Загрузить из файла.\n7)Выход." << std::endl;
		while (!(std::cin >> select))
		{
			system("cls");
			std::cout << "Ошибка ввода." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "1)Добавить группу или студента.\n2)Удалить группу или студента.\n3)Поиск.\n4)Вывод.\n5)Сохранить в файл.\n6)Загрузить из файла.\n7)Выход." << std::endl;
		}
		if (select == 1)
		{
			faculty->addContent();
		}
		else if (select == 2)
		{
			faculty->deleteContent();
		}
		else if (select == 3)
		{
			faculty->search();
		}
		else if (select == 4)
		{
			if (faculty->getName() == NULL)
			{
				std::cout << "Факультет пуст." << std::endl;
				continue;
			}
			faculty->show();
		}
		else if (select == 5)
		{
			faculty->saveInFile();
		}
		else if (select == 6)
		{
			if (faculty->getName() != NULL)
			{
				std::cout << "Текущий факультет будет удален. Желаете продолжить?\n1)Да.\n2)Нет.\n" << std::endl;
				int select;
				while (!(std::cin >> select))
				{
					system("cls");
					std::cout << "Ошибка ввода." << std::endl;
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "Текущий факультет будет удален. Желаете продолжить?\n1)Да.\n2)Нет.\n" << std::endl;
				}
				if (select == 1)
				{
					delete(faculty);
					faculty = new Faculty();
				}
				else if (select == 2)
				{
					continue;
				}
			}
			faculty->LoadFromFile();
		}
		else if (select == 7)
		{
			delete(faculty);
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}