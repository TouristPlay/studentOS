#include "rating.h"

#include "discipline.h";

// Конструктор
rating::rating(discipline subject, string grade) {
	this->grade = grade;
	this->subject = subject;
}

// Метод для получение имени предмета
string rating::getName() {
	return this->subject.getName();
}

// Метод для получения оценки предмета
string rating::getGrade() {
	return this->grade;
}

// Метод для изменение оценки
void rating::setGrade(string grade) {
	this->grade = grade;
}