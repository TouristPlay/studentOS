#include "library.h"

#include "discipline.h"

class studentList;

class session {


	public:
		// �����������
		session();

		session(string newType, string newData, discipline newSubject);

		// ����� ��� ��������� ���� ����� ������
		string getType();

		// ����� ��� ��������� ���� ����� ������
		string getDate();

		// ����� ��� ��������� ����� ����������
		string getDisciplineName();

		// ����� ��� ��������� ID ���������� 
		unsigned getDisciplineID();

		// ����� ��� ��������� ���� ������
		void setDate(string newDate);

		// ���� ��� ��������� ���� ������
		void setType(string newType);
		

	private:	

		string type; // ��� ����� �������/�����/��������
		string date; // ���� ����� ��������
		discipline subject; // ������� ��� �����


		friend studentList;
};
