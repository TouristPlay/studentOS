#include "session.h"

#include "discipline.h"

// �����������
session::session() {
	this->date = "";
	this->type = "";
}

// �����������
session::session(string newType, string newData, discipline newSubject) {
	this->date = newData;
	this->type = newType;
	this->subject = newSubject;
}

// ����� ��� ��������� ���� ����� ������
string session::getType() {
	return this->type;
}

// ����� ��� ��������� ���� ����� ������
string session::getDate() {
	return this->date;
}

// ����� ��� ��������� ����� ����������
string session::getDisciplineName() {
	return this->subject.getName();
}

// ����� ��� ��������� ���� ������
void session::setDate(string newDate) {
	this->date = newDate;
}

// ���� ��� ��������� ���� ������
void session::setType(string newType) {
	this->type = newType;
}

// ����� ��� ��������� ID ���������� 
unsigned session::getDisciplineID() {
	return this->subject.getID();
}