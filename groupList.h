#include "library.h"

class studentList;
class reports;
class ratingList;

class groupList {
	public: // ��������� ������� ������

		// ����� ���������� ������ �����
		bool read(studentList _student, string filename = "group");

		// ����� ��� ������ ������ ��������� � ����
		bool write(string filename = "newGroup");

		// ����� ���������� ������ � ������
		bool create(studentList _student);

		// ����� ��������� ���������� � ������
		bool update(int id, studentList _student);

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

		// ����� ���������, ���� �� ������� � ������
		bool checkStudent(string group, studentList _student);

		// ����� ��� �������� ���������� �� ������
		bool checkGroup(string groupNumber);

		// ����� ��� ���������� ������
		void input();

		// ������ ���� ������
		vector <map<string, string>> _groupList; // �������!!!!

		// ��������� ������������� �����
		friend studentList;
		friend reports;
		friend ratingList;
};

