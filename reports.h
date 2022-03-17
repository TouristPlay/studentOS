#include "library.h"

class deliveryDisciplines;
class ratingList;
class studentList;
class groupList;

class reports {

	public:

		// ����� ������ ��������� ��� ����� ���������� ������
		bool getGroupDiscipline(string groupNumber, deliveryDisciplines _deliveryDisciplines);

		// ����� ������ ��������� ����� ����������
		bool getFacultyDescipline(deliveryDisciplines _deliveryDisciplines);

		// ����� ������ ������ ��������
		bool getStudentGrade(ratingList _rating, studentList _student);

		// ����� ������ ������ �������� ��������� ������
		bool getGroupGrade(ratingList _rating, groupList _group);

		// ����� ������ ��������� �� ������� ������
		bool getStudentNotPassSession(ratingList _rating);

		// ����� ������ �������� ����� �� ������
		double getGroupAverage(ratingList _rating, string groupNumber);

		// ����� ������ ��������� ����� �� ����������
		double getFacultyAverage(ratingList _rating, studentList _student);

	private:

};

