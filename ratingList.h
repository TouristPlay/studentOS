#include "library.h"


class deliveryDisciplines;
class studentList;
class reports;

// ����� ����� ������������
class ratingList {

	public:

		// ����� ��� ���������� ������ ��������
		bool create(string group, deliveryDisciplines _disciplineList, studentList _studentList);

	private:

		struct rating
		{
			string discipline;
			string grade;
		};

		rating _ratingInfo;

		// ����� ��� ������ ��������� ����������� ������
		void findStudent(string group, studentList _studentList);

		// ����� ��������� ���� �� ����� ����������

		// ����� ��������� ����� �������� �� ID 
		string getStudentNameByID(int id, studentList _studentList);

		// ����� ��������� ���� ��������� � ���������� � ������
		bool insertAllStudent(string group, deliveryDisciplines _disciplineList, studentList _studentList);


		map<string, map<string, vector<rating>>> _ratingList;
		//map<������, map<�������, vector<����������, ������>>

		friend reports;
};


