#include "library.h"

// ���������� �������
#include "studentList.h"
#include "groupList.h"
#include "disciplineList.h"
#include "deliveryDisciplines.h"
#include "ratingList.h"
#include "reports.h"

//public: // ��������� ������� ������
//
//private: // �������� ������� ������

// ������� ����� DB 
// � ��� ����� ��� ����
// ������ ��� ��������� ���������� DB

// ��� � ����������
// ������������ ���������� - ����� ������� � �������� ��� �������� // ��������� ����


int main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	groupList group;
	studentList student;
	disciplineList discipline;
	deliveryDisciplines delivery;
	ratingList rating;
	reports _reports;

	group.read(student);

	student.read(group);
	student.output();


	discipline.read();
	discipline.output();

	delivery.create(discipline, "241");
	//delivery.create(discipline, "141");

	delivery.output("241");

	rating.create("241", delivery, student);
	rating.create("241", delivery, student);


	_reports.getGroupDiscipline("241", delivery);

	_reports.getFacultyDescipline(delivery);

	_reports.getStudentGrade(rating, student);


	//_reports.getGroupGrade(rating, group);

	//rating.create("241", delivery, student);

	//_reports.getGroupGrade(rating, group);


	_reports.getStudentNotPassSession(rating);


	cout << _reports.getGroupAverage(rating, "241") << endl;

	cout << _reports.getFacultyAverage(rating);

	system("pause");
	return 0;
}