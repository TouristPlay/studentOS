#include "group.h"

#include "disciplineList.h"

// ����������� ������
group::group(string newGroup, string newCourse, string newSpeciality) {
	this->groupNumber = newGroup;
	this->course = newCourse;
	this->speciality = newSpeciality;
	this->ID = this->idGenerator++;
}

// ����������� ������
group::group() {
	this->groupNumber = "";
	this->course = "";
	this->speciality = "";
}

// ����� ��� ��������� ����� ������
string group::getCourse() {
	return this->course;
}

// ����� ��� ��������� ������ ������
string group::getGroup() {
	return this->groupNumber;
}

// ���� ��� ��������� ������������� ������
string group::getSpeciality() {
	return this->speciality;
}

// ����� ��� ��������� ID
unsigned group::getID() {
	return this->ID;
}

// ����� ��� ��������� ����� ������
void group::setCourse(string newCourse) {
	this->course = newCourse;
}

// ����� ��� ��������� ������ ������
void group::setGroup(string newGroup) {
	this->groupNumber = newGroup;
}

// ���� ��� ��������� ������������� ������
void group::setSpeciality(string newSpeciality) {
	this->speciality = newSpeciality;
}

// ��������� ID
unsigned group::idGenerator = 1;

// ����� ��� ������ ��������� ��� �����
bool group::getDiscipline() {

	if (this->_session.empty()) {
		return false;
	}

	int counter = 1;

	for (auto element : this->_session) {
		cout << left << "\t #" << counter << " | " 
			<< setw(25) << element.getDisciplineName() << " | "
			<< setw(15) << element.getType() << " | "
			<< element.getDate() << endl;
		counter++;
	}
	return true;
}