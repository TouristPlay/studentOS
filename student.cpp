#include "student.h"


// Конструктор класса 
student::student() {
	this->name = "";
	this->surename = "";
	this->middlename = "";
	this->sex = "";
	this->group = "";
}

student::student(string newName, string newSurename, string newMiddlename, string newSex, string newGroup) {
	this->name = newName;
	this->surename = newSurename;
	this->middlename = newMiddlename;
	this->sex = newSex;
	this->group = newGroup;
	this->ID = this->idGenerator++;
}

// Метод для получения имени студента
string student::getName() {
	return this->surename + " " + this->name + " " + this->middlename;
}

// Метод для получения пола студента
string student::getSex() {
	return this->sex;
}

// Метод для получения группы
string student::getGroup() {
	return this->group;
}

// Метод для получения ID
unsigned student::getID() {
	return this->ID;
}

// Метод для изменнеия имени студента
void student::changeName(string newName, string newSurename, string newMiddlename) {
	this->name = newName;
	this->surename = newSurename;
	this->middlename = newMiddlename;
}

// Метод для изменнеия пола
void student::changeSex(string newSex) {
	this->sex = newSex;
}

// Метод для изменения грурры
void student::changeGroup(string newGroup) {
	this->group = newGroup;
}

// Генератор ID
unsigned student::idGenerator = 1;