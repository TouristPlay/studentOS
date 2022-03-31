#include "session.h"

#include "discipline.h"

// Конструктор
session::session() {
	this->date = "";
	this->type = "";
}

// Конструктор
session::session(string newType, string newData, discipline newSubject) {
	this->date = newData;
	this->type = newType;
	this->subject = newSubject;
}

// Метод для получения типа сдачи сессии
string session::getType() {
	return this->type;
}

// Метод для получения даты сдачи сессии
string session::getDate() {
	return this->date;
}

// Метод для получении имени дисциплины
string session::getDisciplineName() {
	return this->subject.getName();
}

// Метод для изменения даты сессии
void session::setDate(string newDate) {
	this->date = newDate;
}

// Мето для изменения типа сессии
void session::setType(string newType) {
	this->type = newType;
}

// Метод для получение ID дисциплины 
unsigned session::getDisciplineID() {
	return this->subject.getID();
}