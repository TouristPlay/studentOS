#include "library.h"

class groupList;
class ratingList;
class reports;

class studentList {
	public: // ��������� ������� ������

		// ����� ���������� ������ ��������� � �����
		bool read(groupList _group, string filename = "student");

		// ����� ��� ������ ������ ��������� � ����
		bool write(string filename = "newStudent");

		// ����� ���������� �������� � ������
		bool create(groupList _group);

		// ����� ��������� ���������� � ��������
		bool update(int id, groupList _group);

		// ����� �������� ���������� � ��������
		bool remove(int id);

		// ����� ������ ��������� � �������
		bool output();

	private: // �������� ������� ������

		// ��������� ��� �������� ���
		string name, surename, middlename;
		// ������ ��� ��������
		string sex;
		// ����� ������ 
		string group;

		// ������ ������������������ ������ � map
		vector<string> writeQueue = {
			"surename",
			"name",
			"middlename",
			"group",
			"sex"
		};


		// ����� ��� �������� ������ ��������
		void append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);


		// ����� �������� ��������� ������
		void resetVariables();

		// ����� �������� ������ 
		string assemblyString(map<string, string> element);

		// ����� ��� �������� ���� �� ������ ���������
		bool empty();

		// ����� ��� �������� ���������� �� ������
		bool checkGroup(string groupNumber, groupList _group);

		// ������ ������ ���������� � ���������
		vector<map<string, string>> _studentList; // �������

		// ��������� ������������� �����
		friend ratingList;
		friend groupList;
		friend reports;
};

