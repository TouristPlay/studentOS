#include "library.h"

class discipline;
class studentList;
class groupList;

class disciplineList {

	public:
		// �������� ����� ������ ������ ��������� �� �����
		bool read(string filename = "discipline");

		// �������� ����� ������ ������ ��������� � ����
		bool write(string filename = "newDiscipline");

		// �������� ����� ������� ����� ����������
		bool create();

		// �������� �������������� ���������� � ������
		bool update(unsigned id);

		// �������� ����� �������� ���������� � ������
		bool remove(unsigned id);

		// �������� ����� ������ ������ ����� � �������
		bool output();

	private:

		string disciplineName;

		// ��������� ����� ��� �������� ���� �� ������ ���������
		bool empty();

		// ����� ��������� ���������� �� ID
		discipline &getDisciplineByID(unsigned ID);

		// ����� ��������, ���� �� ��� ����� ����������
		bool checkDiscipline(string disciplineName);

		// ����� ��� �������� ���������� �� ����� ID
		bool checkID(unsigned ID);

		// ������ ���������
		vector<discipline> _disciplineList;

		friend groupList;
		friend studentList;
};

