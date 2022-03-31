#include "student.h"


// ����������� ������ 
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

// ����� ��� ��������� ����� ��������
string student::getName() {
	return this->surename + " " + this->name + " " + this->middlename;
}

// ����� ��� ��������� ���� ��������
string student::getSex() {
	return this->sex;
}

// ����� ��� ��������� ������
string student::getGroup() {
	return this->group;
}

// ����� ��� ��������� ID
unsigned student::getID() {
	return this->ID;
}

// ����� ��� ��������� ����� ��������
void student::changeName(string newName, string newSurename, string newMiddlename) {
	this->name = newName;
	this->surename = newSurename;
	this->middlename = newMiddlename;
}

// ����� ��� ��������� ����
void student::changeSex(string newSex) {
	this->sex = newSex;
}

// ����� ��� ��������� ������
void student::changeGroup(string newGroup) {
	this->group = newGroup;
}

// ��������� ID
unsigned student::idGenerator = 1;