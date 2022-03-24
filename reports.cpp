#include "reports.h"

#include "deliveryDisciplines.h"
#include "ratingList.h"
#include "studentList.h"
#include "groupList.h"


// ����� ������ ��������� ��� ����� ���������� ������
bool reports::getGroupDiscipline(string groupNumber, deliveryDisciplines _deliveryDisciplines, groupList _group) {

	// ���� ������ ����
	if (_deliveryDisciplines.empty() || _group.empty()) {
		return false;
	}

	if (_group.empty()) {
		return false;
	}

	
	if (!_group.checkGroup(groupNumber)) {
		cout << " ������ \"" << groupNumber << "\" �� ����������" << endl;
		return false;
	}

	
	// �������� �����
	ofstream file("GroupDiscipline-" + groupNumber + ".txt");


	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	int counter = 1;

	for_each(_deliveryDisciplines._deliveryDisciplines[groupNumber].begin(), _deliveryDisciplines._deliveryDisciplines[groupNumber].end(),
		[&counter, &file](deliveryDisciplines::discipline item) {
			// ������� � �������
			cout << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			file << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			++counter;
		}	
	);

	return true;
}

// ����� ������ ��������� ����� ����������
bool reports::getFacultyDescipline(deliveryDisciplines _deliveryDisciplines) {
	
	// ���� ������ ����
	if (_deliveryDisciplines.empty()) {
		return false;
	}

	// �������� �����
	ofstream file("GroupDiscipline.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	_deliveryDisciplines.element = _deliveryDisciplines._deliveryDisciplines.begin();

	for (int i = 0; _deliveryDisciplines.element != _deliveryDisciplines._deliveryDisciplines.end(); _deliveryDisciplines.element++) {
		int counter = 1;

		cout << " ���������� \"" << _deliveryDisciplines.element->first << "\" ������ ��� �����"<< endl;
		file << " ���������� \"" << _deliveryDisciplines.element->first << "\" ������ ��� �����"<< endl;

		for_each(_deliveryDisciplines.element->second.begin(), _deliveryDisciplines.element->second.end(),
			[&counter, &file](deliveryDisciplines::discipline item) {
				// ������� � �������
				cout << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
				file << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
				++counter;
			}
		);

		cout << endl;
		file << endl;
	}

	return true;
}

// ����� ������ ������ ��������
bool reports::getStudentGrade(ratingList _rating, studentList _student) {

	if (_rating.empty()) {
		return false;
	}

	if (_student.empty()) {
		return false;
	}
	
	// ������� ������ ���� ���������
	_student.output();

	int studentID;

	cout << " ������� ID ��������: ";
	cin >> studentID;

	// ���� ��� ������ ��������
	if (studentID < 0 || (unsigned) studentID > _student._studentList.size()) {
		cout << " �������� � ID-" << studentID << " �� ����������" << endl;
		return false;
	}

	// �������� ��� �������� 
	string studentName = _rating.getStudentNameByID(studentID, _student);

	// �������� �����
	ofstream file(studentName + " Grade" + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}



	// �������� ������ ��������
	string studentGroup = _student._studentList[studentID - 1]["group"];

	cout << " ������ �������� \"" << studentName << "\" \"" << studentGroup << "\" ������" << endl;
	file << " ������ �������� \"" << studentName << "\" \"" << studentGroup << "\" ������" << endl;

	int counter = 1;


	// �������� �� ������ ��������� �� ������
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[studentGroup].begin();

	// ����� ������ ������ ��� ��������
	for (; element != _rating._ratingList[studentGroup].end(); ++element) {
		//������� ��������
		if (element->first == studentName) {
			for (ratingList::rating item : element->second) {
				cout << " \t #" << counter << " " << item.discipline << " - " << item.grade << endl;
				file << " \t #" << counter << " " << item.discipline << " - " << item.grade << endl;
				++counter;
			}
			break;
		}
	}

	return true;
}

// ����� ������ ������ ��������� ��������� ������
bool reports::getGroupGrade(ratingList _rating, groupList _group) {
	
	if (_rating.empty()) {
		return false;
	}

	if (_group.empty()) {
		return false;
	}

	string groupNumber;

	cout << " ������� ����� ������: ";
	cin >> groupNumber;

	if (!_group.checkGroup(groupNumber)) {
		cout << " ������ \"" << groupNumber << "\" �� ����������" << endl;
		return false;
	}


	// �������� �����
	ofstream file(groupNumber + "group grade" + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}



	cout << " ������ ��������� \"" << groupNumber <<  "\" ������" << endl;
	file << " ������ ��������� \"" << groupNumber <<  "\" ������" << endl;

	// �������� �� ������ ��������� �� ������
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[groupNumber].begin();

	cout << "\t " << setw(38) << "  ";
	file << "\t " << setw(38) << "  ";

	// ����� ���������
	for (ratingList::rating item : element->second) {
		file << left << setw(25) << item.discipline;
		cout << left << setw(25) << item.discipline;
	}

	cout << endl;
	file << endl;

	// ����� ������ ������ ��� ��������
	for (int counter = 1; element != _rating._ratingList[groupNumber].end(); ++element, ++counter) {
		cout << "\t #" << counter << " " << setw(35) << element->first; // ������� ���
		file << "\t #" << counter << " " << setw(35) << element->first; // ������� ���
		// ������� ������
		for (ratingList::rating item : element->second) {
			cout << left << setw(25) << item.grade;
			file << left << setw(25) << item.grade;
		}

		cout << endl;
		file << endl;
	}

	return true;
}

// ����� ������ ��������� �� ������� ������
bool reports::getStudentNotPassSession(ratingList _rating) {

	if (_rating.empty()) {
		return false;
	}

	// �������� �����
	ofstream file("studentNotPassSession.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}


	// �������� ������ 
	map<string, map<string, vector<ratingList::rating>>> :: iterator it = _rating._ratingList.begin();

	// ���������� �� ������ ������ ������� �������� � ������� ��� ��� �� ����
	for (int counter = 1; it != _rating._ratingList.end(); ++it) {

		map<string, vector<ratingList::rating>> ::iterator it2 = it->second.begin();

		for (; it2 != it->second.end(); ++it2, ++counter) {
			vector<ratingList::rating> ::iterator it3 = it2->second.begin();

			for (;it3 != it2->second.end(); ++it3) {
				if (it3->grade == "�� �������" || it3->grade == "�������" || it3->grade == "2") {
					cout << "\t #" << counter << " " << it2->first << " " << it->first << endl;
					file << "\t #" << counter << " " << it2->first << " " << it->first << endl;
					break;
				}
			}
		}

	}

	return true;
}

// ����� ������ �������� ����� �� ������
bool reports::getGroupAverage(ratingList _rating, string groupNumber) {

	if (_rating.empty()) {
		return false;
	}


	// �������� �����
	ofstream file("GroupAverage-" + groupNumber + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	// �������� �� ������ ��������� �� ������
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[groupNumber].begin();

	double average = 0;
	int counter = 0;

	for (; element != _rating._ratingList[groupNumber].end(); ++element, ++counter) {
		for (ratingList::rating item : element->second) {
			if (item.grade == "2" || item.grade == "3" || item.grade == "4" || item.grade == "5") {
				average += stoi(item.grade);
			}
		}
	}


	file << " ������� ������ \"" << groupNumber << "\" ������: ";
	cout << "\t ������� ������ \"" << groupNumber << "\" ������: ";

	if (average == 0) {
		return false;
		file << 0;
		cout << 0 << endl;
	}

	file << average / (double)counter;
	cout << average / (double)counter << endl;;

	return true;
}

// ����� ������ ��������� ����� �� ����������
bool reports::getFacultyAverage(ratingList _rating, studentList _student) {

	if (_rating.empty()) {
		return false;
	}

	if (_student.empty()) {
		return false;
	}

	// �������� �����
	ofstream file("facultyAverage.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}


	// �������� ������ 
	map<string, map<string, vector<ratingList::rating>>> ::iterator it = _rating._ratingList.begin();

	double average = 0;
	int counter = 0;

	// ���������� �� ������ ������ ������� �������� � ������� ��� ��� �� ����
	for (; it != _rating._ratingList.end(); ++it) {

		map<string, vector<ratingList::rating>> ::iterator it2 = it->second.begin();

		for (; it2 != it->second.end(); ++it2, ++counter) {
			vector<ratingList::rating> ::iterator it3 = it2->second.begin();

			for (; it3 != it2->second.end(); ++it3) {
				if (it3->grade == "2" || it3->grade == "3" || it3->grade == "4" || it3->grade == "5") {
					average += stoi(it3->grade);
				}
			}
		}

	}

	file << " ������� ������ ����������: ";
	cout << "\t ������� ������ ����������: ";

	if (average == 0) {
		return false;
		file << 0;
		cout << 0 << endl;
	}

	file << average / (double)_student._studentList.size();
	cout << average / (double)_student._studentList.size() << endl;

	return true;
}
