#include "rating.h"

#include "discipline.h";

// �����������
rating::rating(discipline subject, string grade) {
	this->grade = grade;
	this->subject = subject;
}

// ����� ��� ��������� ����� ��������
string rating::getName() {
	return this->subject.getName();
}

// ����� ��� ��������� ������ ��������
string rating::getGrade() {
	return this->grade;
}

// ����� ��� ��������� ������
void rating::setGrade(string grade) {
	this->grade = grade;
}