#include "discipline.h"

// �����������
discipline::discipline(string newName) {
	this->name = newName;
	this->ID = this->idGenerator++;
}

discipline::discipline() {
	this->name = "";
}

// ����� ��� ��������� ����� ����������
string discipline::getName() {
	return this->name;
}

// ����� ��� ��������� ID ����������
unsigned discipline::getID() {
	return this->ID;
}

// ����� ��� ��������� ����� ID
void discipline::setName(string newName) {
	this->name = newName;
}

unsigned discipline::idGenerator = 1;