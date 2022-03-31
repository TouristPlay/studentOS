#include "group.h"

#include "disciplineList.h"

// Конструктор класса
group::group(string newGroup, string newCourse, string newSpeciality) {
	this->groupNumber = newGroup;
	this->course = newCourse;
	this->speciality = newSpeciality;
	this->ID = this->idGenerator++;
}

// Конструктор класса
group::group() {
	this->groupNumber = "";
	this->course = "";
	this->speciality = "";
}

// Метод для получения курса группы
string group::getCourse() {
	return this->course;
}

// Метод для получения номера группы
string group::getGroup() {
	return this->groupNumber;
}

// Мето для получения специальности группы
string group::getSpeciality() {
	return this->speciality;
}

// Метод для получения ID
unsigned group::getID() {
	return this->ID;
}

// Метод для изменения курса группы
void group::setCourse(string newCourse) {
	this->course = newCourse;
}

// Метод для изменения номера группы
void group::setGroup(string newGroup) {
	this->groupNumber = newGroup;
}

// Мето для изменения специальности группы
void group::setSpeciality(string newSpeciality) {
	this->speciality = newSpeciality;
}

// Генератор ID
unsigned group::idGenerator = 1;

// Метод для вывода дисциплин для сдачи
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