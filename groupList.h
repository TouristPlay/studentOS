#include "library.h"
#include "studentList.h"

class groupList {
	public: // ��������� ������� ������

		// ����� ���������� ������ �����
		bool read(string filename = "group");

		// ����� ��� ������ ������ ��������� � ����
		bool write(string filename = "newGroup");

		// ����� ���������� ������ � ������
		bool create();

		// ����� ��������� ���������� � ������
		bool update(int id);

		// ����� �������� ���������� � ������
		bool remove(int id, studentList _student);

		// ����� ������ ������ ����� � �������
		bool output();

	private: // �������� ������� ������

		// ���� ������
		string course;
		// ����� ������
		string group;
		// ��� �������������
		string speciality;


		// ������ ������������������ ������ � map
		vector<string> writeQueue = {
			"group",
			"course",
			"speciality",
		};

		// ����� ��� �������� ���� �� ������ �����
		bool empty();

		// ����� ��� �������� ����� ������
		void append(string newGroup, string newCourse, string newSpeciality);

		// ����� �������� ��������� ������
		void resetVariables();

		// ����� �������� ������ 
		string assemblyString(map<string, string> element);

		// ����� ���������, ���� ������� � ������
		bool checkStudent(string group, studentList _student);

		// ������ ���� ������
		vector <map<string, string>> _groupList;

		// ��������� ������������� �����
		friend studentList;
};

