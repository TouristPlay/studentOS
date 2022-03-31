#include "discipline.h"

// Конструктор
discipline::discipline(string newName) {
	this->name = newName;
	this->ID = this->idGenerator++;
}

discipline::discipline() {
	this->name = "";
}

// Метод для получения имени дисциплины
string discipline::getName() {
	return this->name;
}

// Метод для получения ID дисциплины
unsigned discipline::getID() {
	return this->ID;
}

// Метод для изменения имени ID
void discipline::setName(string newName) {
	this->name = newName;
}

unsigned discipline::idGenerator = 1;