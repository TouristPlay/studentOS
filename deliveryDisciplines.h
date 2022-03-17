#include "library.h"

class disciplineList;
class ratingList;
class reports;

class deliveryDisciplines {
	public:

		// ��������� ����� ���������� ���������� ��� �����
		bool create(disciplineList _discipline, string groupNumber);

		// ��������� ����� ��������� ����������
		bool update(string groupNumber);

		// ��������� ����� �������� ���������� � ����������
		bool remove(string groupNumber);

		// ��������� ����� ������ ��������� ��� ������
		void output(string groupNumber);
	private:

		string group; // ������
		int disciplineId = 0; // ����������
		string deliveryType; // ��� ����� �������/�����/��������
		string deliveryDate; // ���� ����� ��������

		// ������ ������ �� ����� ����������
		struct discipline
		{
			string name; // ��� ����������
			string type; // ��� �����
			string date; // ���� �����
		};

		discipline disciplineInfo;

		// ����� ���������� ���������� � ������ �����
		bool append(string newGroup, string newDisciplineId, string newDeliveryType, string newDeliveryDate);

		// ����� ��� ��������� ����������
		void resetVariabless();

		// ����� ��������� ��������� ���������� ����������
		bool repeatInclude(string subjectName, string groupNumber);

		// ����� ��� �������� ������ �� ������
		bool empty();

		// �������� ������ ��������� ��������� ��� ������
		map <string, vector<discipline>> _deliveryDisciplines;

		// �������� �� ������ 
		map <string, vector<discipline>> ::iterator element;
		

		friend ratingList;
		friend reports;
};
