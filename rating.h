#include "library.h"

#include "discipline.h"
class studentList;
class groupList;

class rating {


	public:

		// �����������
		rating(discipline subject, string grade);

		// ����� ��� ��������� ����� ��������
		string getName();

		// ����� ��� ��������� ������ ��������
		string getGrade();

		// ����� ��� ��������� ������
		void setGrade(string grade);

	private:

		discipline subject; // ����������
		string grade; // ������

		friend studentList;
		friend groupList;
};

