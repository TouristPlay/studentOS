#include "library.h"

// ���������� �������
#include "studentList.h"
#include "groupList.h"
#include "disciplineList.h"


//public: // ��������� ������� ������
//
//private: // �������� ������� ������

// ������� ����� DB 
// � ��� ����� ��� ����
// ������ ��� ��������� ���������� DB


// ��������� ����� � ���������� ��� � �����


int main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	groupList group;
	studentList student;
	disciplineList discipline;


	group.read();


	student.read(group);
	student.output();

	student.create(group);
	student.output();


	group.output();
	group.remove(1, student);

	system("pause");
	return 0;
}