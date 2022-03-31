#include "library.h"
#include "session.h"

class disciplineList;
class groupList;
class studentList;

class group {

	public:

		// ����������� ������
		group(string newGroup, string newCourse, string newSpeciality);

		// ����������� ������
		group();

		// ����� ��� ��������� ����� ������
		string getCourse();

		// ����� ��� ��������� ������ ������
		string getGroup();

		// ���� ��� ��������� ������������� ������
		string getSpeciality();

		// ����� ��� ��������� ID
		unsigned getID();

		// ����� ��� ��������� ����� ������
		void setCourse(string newCourse);

		// ����� ��� ��������� ������ ������
		void setGroup(string newGroup);

		// ���� ��� ��������� ������������� ������
		void setSpeciality(string newSpeciality);

		// ����� ��� ������ ��������� ��� �����
		bool getDiscipline();

	private:	

		// ���� ������
		string course;
		// ����� ������
		string groupNumber;
		// ��� �������������
		string speciality;
		// ID
		unsigned ID;
		// ��������� ID
		static unsigned idGenerator;

		// ������ ��������� ��� �����
		vector <session> _session; 

		friend groupList;
		friend studentList;
};

