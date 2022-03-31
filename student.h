#include "library.h"

#include "rating.h"

class studentList;
class groupList;

class student {

	public:

		// ����������� ������ 
		student();

		student(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);

		// ����� ��� ��������� ����� ��������
		string getName();

		// ����� ��� ��������� ���� ��������
		string getSex();

		// ����� ��� ��������� ������
		string getGroup();

		// ����� ��� ��������� ID
		unsigned getID();

		// ����� ��� ��������� ����� ��������
		void changeName(string newName, string newSurename, string newMiddlename);

		// ����� ��� ��������� ����
		void changeSex(string newSex);

		// ����� ��� ��������� ������
		void changeGroup(string newGroup);

	private:

		// ��������� ��� �������� ���
		string name, surename, middlename;
		// ������ ��� ��������
		string sex;
		// ����� ������ 
		string group;
		// ID
		unsigned ID;
		// ��������� ID
		static unsigned idGenerator;

		// ������ ������ �� ������
		vector<rating> _rating;

		friend studentList;
		friend groupList;
};

