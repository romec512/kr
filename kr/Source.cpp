#include <locale.h>
#include "Student.h"
#include <iostream>
#include "Group.h"
#include "Faculty.h"
void main()
{
	setlocale(LC_ALL, "rus");
	Faculty *faculty = new Faculty(6);
	for (int i = 0; i < 5; i++)
	{
		Group *group = new Group();
		group->setNumber(4210+2*i);
		Student *ivanov = new Student("ivanov", 1998);
		Student *loseva = new Student("loseva", 1999);
		Student *asadov = new Student("asadov", 1998);
		Student *pirogov = new Student("pirogov", 2013);
		Student *lolkek = new Student("lolkek", 2120);
		group->addStudent(ivanov);
		group->addStudent(asadov);
		group->addStudent(loseva);
		group->addStudent(pirogov);
		group->addStudent(lolkek);
		faculty->addGroup(group);
	}
	Group *gr = new Group();
	gr->setNumber(4211);
	faculty->addGroup(gr);
	faculty->deleteStudent();
	Group **mass = faculty->getMass();
	system("pause");
}