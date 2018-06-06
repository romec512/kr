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
		std::cout << "1)�������� ������ ��� ��������.\n2)������� ������ ��� ��������.\n3)�����.\n4)�����.\n5)��������� � ����.\n6)��������� �� �����.\n7)�����." << std::endl;
		while (!(std::cin >> select))
		{
			system("cls");
			std::cout << "������ �����." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "1)�������� ������ ��� ��������.\n2)������� ������ ��� ��������.\n3)�����.\n4)�����.\n5)��������� � ����.\n6)��������� �� �����.\n7)�����." << std::endl;
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
				std::cout << "��������� ����." << std::endl;
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
				std::cout << "������� ��������� ����� ������. ������� ����������?\n1)��.\n2)���.\n" << std::endl;
				int select;
				while (!(std::cin >> select))
				{
					system("cls");
					std::cout << "������ �����." << std::endl;
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "������� ��������� ����� ������. ������� ����������?\n1)��.\n2)���.\n" << std::endl;
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