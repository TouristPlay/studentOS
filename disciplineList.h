#include "library.h"

class deliveryDisciplines;

// ����� ���������
class disciplineList {
	public: // ��������� ������� ������

		// �������� ����� ������ ������ ��������� �� �����
		bool read(string filename = "discipline");

		// �������� ����� ������ ������ ��������� � ����
		bool write(string filename = "newDiscipline");

		// �������� ����� ������� ����� ����������
		bool create();

		// �������� �������������� ���������� � ������
		bool update(int id);

		// �������� ����� �������� ���������� � ������
		bool remove(int id);

		// �������� ����� ������ ������ ����� � �������
		bool output();


	private: // �������� ������� ������

		string disciplineName;

		// ��������� ����� ��� �������� ���� �� ������ ���������
		bool empty();

		// ������ ���������
		vector<string> _disciplineList;

		// ��������� ������������� �����
		friend deliveryDisciplines;
};

