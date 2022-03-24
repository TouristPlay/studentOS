#include "library.h"


class deliveryDisciplines;
class studentList;
class reports;
class groupList;

// ����� ����� ������������
class ratingList {

	public:

		// ����� ��� ���������� ������ ��������
		bool create(string group, deliveryDisciplines _disciplineList, studentList _studentList, groupList _group);

	private:

		struct rating
		{
			string discipline;
			string grade;
		};

		rating _ratingInfo;

		// ����� ��� ������ ��������� ����������� ������
		bool findStudent(string group, studentList _studentList);

		// ����� ��������� ���� �� ����� ����������

		// ����� ��������� ����� �������� �� ID 
		string getStudentNameByID(int id, studentList _studentList);

		// ����� ��������� ���� ��������� � ���������� � ������
		bool insertAllStudent(string group, deliveryDisciplines _disciplineList, studentList _studentList);

		// ����� �������� ���� �� ������ ������ 
		bool empty();

		map<string, map<string, vector<rating>>> _ratingList;
		//map<������, map<�������, vector<����������, ������>>

		friend reports;
};


