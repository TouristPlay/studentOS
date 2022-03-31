#include "library.h"
#include "group.h"

class studentList;

class groupList {

	public:

		// ����� ���������� ������ �����
		bool read(string filename = "group");

		// ����� ��� ������ ������ ��������� � ����
		bool write(string filename = "newGroup");

		// ����� ���������� ������ � ������
		bool create();

		// ����� ��������� ���������� � ������
		bool update(unsigned id);

		// ����� �������� ���������� � ������
		bool remove(unsigned id, studentList &_student);

		// ����� ������ ������ ����� � �������
		bool output();

		// ����� ���������� ���������� ��� �����
		bool createDiscipline(disciplineList& _discipline, studentList &_student, unsigned ID);

		// ����� ��� ���������� �������� ��� �����
		bool updateDiscipline(unsigned ID);

		// ����� ��� �������� �������� ��� �����
		bool removeDiscipline(unsigned ID);

		// ����� ��� ��������� ������ ���������
		bool getGroupDiscipline(unsigned ID);

		// ����� ������ ��������� ����� ����������
		bool getFacultyDescipline();

	private:

		// ���� ������
		string course;
		// ����� ������
		string groupNumber;
		// ��� �������������
		string speciality;

		// ����� ��� �������� ���� �� ������ �����
		bool empty();

		// ����� ��� �������� ����� ������
		void append(string newGroup, string newCourse, string newSpeciality);

		// ����� �������� ��������� ������
		void resetVariables();

		// ����� ��� �������� ���������� �� ������
		bool checkGroup(string groupNumber);

		// ����� ���������, ���� �� ������� � ������
		bool checkStudent(string group, studentList &_student);

		// ����� ���������� ������ �� ID
		group &getGroupByID(unsigned ID);

		// ����� ��������� ���� �� ����� ID
		bool checkID(unsigned ID);

		// ����� ��� ���������� ������
		void input();

		// ������ ���� �����
		vector <group> _groupList; 

		friend studentList;
};

