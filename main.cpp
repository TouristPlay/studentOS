#include "library.h"

#include "studentList.h"
#include "disciplineList.h"
#include "groupList.h"


class menu {
public:

	// ������� ��� ������ ��������� ����
	void main() {

		// ������� �����
		header();

		cout << " ������� ����" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. ������" << endl;
		cout << "\t 2. ��������" << endl;
		cout << "\t 3. ����������" << endl;
		cout << "\t 4. ������" << endl;
		cout << "\t 5. ������" << endl;
		cout << "\t 6. ������" << endl;

		cout << endl;



	}


	// ������� ������ ���� ������ �����
	void group() {

		// ������� �����
		header();

		cout << " ������� ���� --> ������" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. ������� � �����" << endl;
		cout << "\t 2. ������ � ����" << endl;
		cout << "\t 3. �������� ������" << endl;
		cout << "\t 4. �������� ������" << endl;
		cout << "\t 5. ������� ������" << endl;
		cout << "\t 6. ������� ������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}


	// ������� ������ ���� ������ ��������
	void student() {

		// ������� �����
		header();

		cout << " ������� ���� --> ��������" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. ������� � �����" << endl;
		cout << "\t 2. ������ � ����" << endl;
		cout << "\t 3. �������� ��������" << endl;
		cout << "\t 4. �������� ��������" << endl;
		cout << "\t 5. ������� ��������" << endl;
		cout << "\t 6. ������� ������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}

	// ������� ������ ���� ������ ����������
	void discipline() {

		// ������� �����
		header();

		cout << " ������� ���� --> ����������" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. ������� � �����" << endl;
		cout << "\t 2. ������ � ����" << endl;
		cout << "\t 3. �������� ����������" << endl;
		cout << "\t 4. �������� ����������" << endl;
		cout << "\t 5. ������� ����������" << endl;
		cout << "\t 6. ������� ������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}

	// ������� ������ ���� ������ ������
	void delivery() {

		// ������� �����
		header();

		cout << " ������� ���� --> ������" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. �������� ����������" << endl;
		cout << "\t 2. �������� ����������" << endl;
		cout << "\t 3. ������� ����������" << endl;
		cout << "\t 4. ������� ������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}


	// ������� ������ ���� ������ ������
	void rating() {

		// ������� �����
		header();

		cout << " ������� ���� --> ������" << endl;
		cout << "\n �������� ����� ����: " << endl;

		cout << "\t 1. �������� ������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}



	// ������� ������ ���� ������ ������
	void report() {

		// ������� �����
		header();

		cout << "\t 1. ���������� ������" << endl;
		cout << "\t 2. ���������� ���������� " << endl;
		cout << "\t 3. ������ ��������" << endl;
		cout << "\t 4. ������ ������" << endl;
		cout << "\t 5. ������ ���������� ������" << endl;
		cout << "\t 6. ������� ������ �� ������" << endl;
		cout << "\t 7. ������� ������ �� ����������" << endl;
		cout << "\t 0. �����" << endl;

		cout << endl;
	}


private:

	// ������� ����� OS
	void header() {

		// ����� ����
		cout << "**********************************************************************" << endl;
		cout << endl;

		cout << setw(40) << "_StudentOS_" << endl;
		cout << setw(48) << "product by TouristTechology" << endl;

		cout << endl;
		cout << "**********************************************************************" << endl;

		cout << endl;
	}
};

// ������� ��� ����������� ������
void proceed();

int main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������ ��������� �������
	SetConsoleTitle(L"StudentOS by TouristTechology");

	// ������� �������
	groupList group;
	studentList student;
	disciplineList discipline;
	menu _menu;

	// ��������������� ��������� ��� ����
	int menuItem = 0;
	int id = 0;
	bool flag;
	string filename;
	string change;
	string groupNumber;

	// ��������� OS
	do {
		system("cls");
		_menu.main();

		cout << " ������� ����� ����: ";
		cin >> menuItem;

		switch (menuItem) {
		case 1: // ������� ���� �����

			do {
				system("cls");
				_menu.group();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // ����������� � �����
					cout << " ���� ���������� �� ��������� group. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = group.read(filename);
					}
					else {
						flag = group.read();
					}


					if (flag) {
						cout << " ���� ������� ������" << endl;
					}


					// ����������� ������
					proceed();

					break;
				case 2:	// ������ �  ����
					cout << " ���� ������ �� ��������� newGroup. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = group.write(filename);
					}
					else {
						flag = group.write();
					}

					if (flag) {
						cout << " ������ ������� � ����" << endl;
					}
					else {
						cout << " ������ ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 3: // �������� ������

					if (group.create()) {
						cout << " ������ ������� ��������� � ������" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 4: // �������� ������

					group.output();
					cout << endl;

					cout << " ������� ID ������: ";
					cin >> id;

					if (group.update(id) == false) {
						cout << " ������ ���� ��� ������ �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 5: // ������� ������

					group.output();
					cout << endl;

					cout << " ������� ID ������: ";
					cin >> id;

					if (group.remove(id, student) == false) {
						cout << " ������ ���� ��� ������ �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 6: // ������� ������


					if (group.output() == false) {
						cout << " ������ ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
					// �����
				case 0:

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}


			} while (menuItem != 0);


			break;
		case 2:// ������� ���� ���������

			do {
				system("cls");
				_menu.student();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // ����������� � �����
					cout << " ���� ���������� �� ��������� student. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = student.read(group, filename);
					}
					else {
						flag = student.read(group);
					}


					if (flag) {
						cout << " ���� ������� ������" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 2:	// ������ �  ����
					cout << " ���� ������ �� ��������� newStudent. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = student.write(filename);
					}
					else {
						flag = student.write();
					}

					if (flag) {
						cout << " ������ ������� � ����" << endl;
					}
					else {
						cout << " ������ ����" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 3: // �������� ��������

					if (student.create(group)) {
						cout << " ������� ������� ��������� � ������" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 4: // �������� ��������

					if (!student.output()) {
						cout << " ������ ����!" << endl;
						// ����������� ������
						proceed();
						break;
					}
					cout << endl;

					cout << " ������� ID ��������: ";
					cin >> id;

					if (!student.update(id)) {
						cout << " �������� �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 5: // ������� ��������

					if (!student.output()) {
						cout << " ������ ����!" << endl;
						// ����������� ������
						proceed();
						break;
					}
					cout << endl;

					cout << " ������� ID ��������: ";
					cin >> id;

					if (!student.remove(id)) {
						cout << " �������� �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 6: // ������� ������


					if (!student.output()) {
						cout << " ������ ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
					// �����
				case 0:

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}
			} while (menuItem != 0);


			break;
		case 3: // ������� ���� ���������

			do {
				system("cls");
				_menu.discipline();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // ����������� � �����
					cout << " ���� ���������� �� ��������� discipline. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = discipline.read(filename);
					}
					else {
						flag = discipline.read();
					}


					if (flag) {
						cout << " ���� ������� ������" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 2:	// ������ �  ����
					cout << " ���� ������ �� ��������� newStudent. ��������? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " ������� ��� �����: ";
						cin >> filename;
						flag = discipline.write(filename);
					}
					else {
						flag = discipline.write();
					}

					if (flag) {
						cout << " ������ ������� � ����" << endl;
					}
					else {
						cout << " ������ ����" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 3: // �������� ����������

					if (discipline.create()) {
						cout << " ���������� ������� ��������� � ������" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 4: // �������� ����������

					if (!discipline.output()) {
						cout << " ������ ����!" << endl;
						// ����������� ������
						proceed();
						break;
					}
					cout << endl;

					cout << " ������� ID ����������: ";
					cin >> id;

					if (discipline.update(id) == false) {
						cout << " ������ ���� ��� ���������� �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 5: // ������� ����������

					if (!discipline.output()) {
						cout << " ������ ����!" << endl;
						// ����������� ������
						proceed();
						break;
					}
					cout << endl;

					cout << " ������� ID ����������: ";
					cin >> id;

					if (discipline.remove(id) == false) {
						cout << " ������ ���� ��� ���������� �� ����������!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 6: // ������� ������


					if (discipline.output() == false) {
						cout << " ������ ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
					// �����
				case 0:

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}
			} while (menuItem != 0);

			break;
		case 4:// ������� ���� ��������� ��� �����

			do {
				system("cls");
				_menu.delivery();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // �������� ����������
					if (!group.output()) {
						cout << " ������ ����" << endl;
						// ����������� ������
						proceed();
						break;
					}

					cout << " ������� ID ������: ";
					cin >> id;

					group.createDiscipline(discipline, student, id);

					// ����������� ������
					proceed();

					break;
				case 2: // �������� ����������
					
					if (!group.output()) {
						cout << " ������ ����" << endl;
						// ����������� ������
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					group.updateDiscipline(id);

					// ����������� ������
					proceed();

					break;
				case 3: // ������� ����������
					
					if (!group.output()) {
						cout << " ������ ����" << endl;
						// ����������� ������
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					group.removeDiscipline(id);

					// ����������� ������
					proceed();

					break;
				case 4: // ������� ������

					if (!group.output()) {
						cout << " ������ ����" << endl;
						// ����������� ������
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					group.getGroupDiscipline(id);

					// ����������� ������
					proceed();

					break;

				case 0:	// �����

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}
			} while (menuItem != 0);

			break;
		case 5: // ������� ���� ������

			do {
				system("cls");
				_menu.rating();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // �������� ����������

					if (!group.output()) {
						cout << " ������ ����" << endl;
						// ����������� ������
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					student.createRating(discipline, group, id);

					// ����������� ������
					proceed();

					break;

				case 0:	// �����

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}


			} while (menuItem != 0);

			break;
		case 6:// ������� ���� �������
			do {
				system("cls");
				_menu.report();


				cout << " ������� ����� ����: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // ���������� ������


					if (!group.output()) {
						cout << " ������ ����!" << endl;
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					if (!group.getGroupDiscipline(id)) {
						cout << " ������ ����� ��� ��������� ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 2: // ���������� ����������

					if (!group.getFacultyDescipline()) {
						cout << " ������ ��������� ��� ����� ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 3: // ������ ��������

					student.getStudentGrade();

					// ����������� ������
					proceed();

					break;
				case 4: // ������ ������

					if (!group.output()) {
						cout << " ������ ����!" << endl;
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;

					student.getGroupGrade(id, group);

					// ����������� ������
					proceed();

					break;
				case 5: // ������ �� ������� ������

					if (!student.getStudentNotPassSession()) {
						cout << " ������ ������ ��� ��������� ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 6: // ������� ������ �� ������

					if (!group.output()) {
						cout << " ������ ����!" << endl;
						proceed();
						break;
					}

					cout << " ������ ID ������: ";
					cin >> id;


					if (!student.getGroupAverage(id, group)) {
						cout << " ������ ������ ����!" << endl;
					}

					// ����������� ������
					proceed();

					break;
				case 7: // ������� ������ �� ����������


					if (!student.getFacultyAverage()) {
						cout << " ������ ������ ��� ��������� ����!" << endl;
					}


					// ����������� ������
					proceed();

					break;
				case 0:	// �����

					break;

				default:
					cout << " ������ ������ ���� �� ����������!" << endl;
					break;
				}


			} while (menuItem != 0);

			break;
		default:
			cout << " ������ ������ ���� �� ����������" << endl;
			break;
		}

	} while (true);



	cout << endl;
	system("pause");
	return 0;
}

// ������� ��� ����������� ������
void proceed() {
	cout << " ��� ����������� ������� ����� �������...";
	char a = getchar();
	a = getchar();
}