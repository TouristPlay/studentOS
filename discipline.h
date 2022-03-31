#pragma once
#include "library.h"


class discipline {

	public:
		// �����������
		discipline(string newName);

		discipline();

		// ����� ��� ��������� ����� ����������
		string getName();

		// ����� ��� ��������� ID ����������
		unsigned getID();

		// ����� ��� ��������� ����� ID
		void setName(string newName);

	private:

		string name; // ��� ���������� 
		unsigned ID; // ID
		// ��������� ID
		static unsigned idGenerator;
};

