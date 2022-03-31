#include "library.h"
#include "student.h"

class disciplineList;
class groupList;

class studentList {
	public:
		// ����� ���������� ������ ��������� � �����
		bool read(groupList &_group, string filename = "student");

		// ����� ��� ������ ������ ��������� � ����
		bool write(string filename = "newStudent");

		// ����� ���������� �������� � ������
		bool create(groupList &_group);

		// ����� ��������� ���������� � ��������
		bool update(unsigned id);

		// ����� �������� ���������� � ��������
		bool remove(unsigned id);

		// ����� ������ ��������� � �������
		bool output();

		// ����� ��� ���������� ������ ��������
		bool createRating(disciplineList &_discipline, groupList &_group, unsigned groupID);

		// ����� ��� ��������� ������ ��������
		bool getStudentGrade();

		// ����� ��� ��������� ������ ����������
		bool getGroupGrade(unsigned groupID, groupList& _group);

		// ����� ��� ��������� ������ ��������� �� ������� ������
		bool getStudentNotPassSession();

		// ����� ��� ��������� �������� ����� �� ������ 
		bool getGroupAverage(unsigned groupID, groupList& _group);

		// ����� ��� ��������� �������� ����� �� ����������
		bool getFacultyAverage();

	private:

		// ��������� ��� �������� ���
		string name, surename, middlename;
		// ������ ��� ��������
		string sex;
		// ����� ������ 
		string groupNumber;

		// ��������� ����� ��� �������� ���� �� ������ ���������
		bool empty();

		// ����� �������� ��������� ������
		void resetVariables();

		// ����� ��������� ���� �� ����� ID
		bool checkID(unsigned ID);

		// ����� ��� �������� ���������� �� ������
		bool checkGroup(string groupNumber, groupList _group);

		// ����� ��� ��������� ��������� ����������� ������
		bool getGroupStudent(string groupName);

		// ����� ��� ����� ������
		void input();

		// ����� �������� �������� �� ID
		student &getStudentByID(unsigned ID);

		// ����� ��� �������� ������ ��������
		void append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);

		// ������ ������ ������ ���������
		vector<student> _studentList;

		friend groupList;
};

