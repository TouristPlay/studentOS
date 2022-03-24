#include "ratingList.h"

#include "studentList.h"
#include "deliveryDisciplines.h"
#include "groupList.h"


// ����� ��� ���������� ������ ��������
bool ratingList::create(string group, deliveryDisciplines _disciplineList, studentList _studentList, groupList _group) {

	
	// ������ �� ����������
	if (!_group.checkGroup(group)) {
		cout << " ������ \"" << group << "\" �� ����������!" << endl;
		return false;
	}

	// ���� � ������ �� ������ ����������
	if (_disciplineList._deliveryDisciplines.find(group) == _disciplineList._deliveryDisciplines.end()) {
		cout << " ���������� ��� ����� �� ������� � \"" << group << "\" ������!" << endl;
		return false;
	}

	// ��������� ������ ��������� ��� ������� �������� 
	insertAllStudent(group, _disciplineList, _studentList);

	// ������� ���� ��������� ����������� ������
	if (!this->findStudent(group, _studentList)) {
		cout << " ��������� � ������ ������ ���!" << endl;
		return false;
	}

	int studentID; // ID ��������
	int disciplineID; // ID ����������

	cout << " ������� ID ��������: ";
	cin >> studentID;

	// ��������� ���� �� ����� ID � ������
	if ((unsigned)studentID > _studentList._studentList.size() || studentID < 1 || _studentList._studentList[studentID - 1]["group"] != group) {
		cout << " �������� � ID-" << studentID << " �� ����������" << endl;
		return false;
	}


	// ������� ������ ��������� ������� ����� ������
	_disciplineList.output(group);

	string status = "Y";
	vector <rating> _rating; // �������� ���������� � ������� ��������

	do {

		cout << " ������� ID ����������: ";
		cin >> disciplineID;

		// ��������� ���� �� ����� ID � ������
		if ((unsigned)disciplineID > _disciplineList._deliveryDisciplines[group].size() || disciplineID < 1) {
			cout << " ���������� � ID-" << disciplineID << " �� ����������" << endl;
			return false;
		}

		// �������� ��� ����������
		string disciplineName = _disciplineList._deliveryDisciplines[group][disciplineID - 1].name;

		// ��� ��������
		string studentName = this->getStudentNameByID(studentID, _studentList);


		map<string, map<string, vector<rating>>> ::iterator it = this->_ratingList.find(group);
		map<string, vector<rating>>::iterator element = it->second.begin();

		// ����������� �� ����� ������ ��������� ������
		for (; element != it->second.end(); ++element) {
			if (studentName == element->first) {
				// �������� �� ������ ���������
				vector <rating> :: iterator item = element->second.begin();
				// ���� ������ ����������
				for (; item != element->second.end(); ++item) {
						if (item->discipline == disciplineName) {
						// ������ ������ ����������
						cout << " ������� ������: ";
						cin >> item->grade;
					}
				}
			}
		}


		cout << " �� ������ ���������� ����? [Y/N]: ";
		cin >> status;

		// ��������� � ������ ��������� ��������
		_rating.push_back(this->_ratingInfo);

		// ���� ���� �������� ��������� ����
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");


	return true;
}

// ����� ��� ������ ��������� ����������� ������
bool ratingList::findStudent(string group, studentList _studentList) {
	int counter = 1;
	bool flag = false;
	for_each(_studentList._studentList.begin(), _studentList._studentList.end(), 
		[&counter, &_studentList, group, &flag](map<string, string> element) {
			// ������� ���� ��������� ������ ������ 
			if (element["group"] == group) {
				cout << " #" << counter << _studentList.assemblyString(element) << endl;
				flag = true;
			}
			++counter;
		}
	);

	return flag;
}

// ����� ��������� ����� �������� �� ID 
string ratingList::getStudentNameByID(int id, studentList _studentList) {
	// ������ ��������
	map<string, string> element = _studentList._studentList[id - 1];

	return element["surename"] + " " + element["name"] + " " + element["middlename"];
}	

// ����� ��������� ���� ��������� � ���������� � ������
bool ratingList::insertAllStudent(string group, deliveryDisciplines _disciplineList, studentList _studentList) {
	
	vector <rating> rating; // �������� ���������� � ������� ��������

	// ��������� ����������
	for_each(_disciplineList._deliveryDisciplines[group].begin(), _disciplineList._deliveryDisciplines[group].end(), 
			[this, &rating](deliveryDisciplines::discipline element) {
				// ��� ����������
				this->_ratingInfo.discipline = element.name;
				// ������ ������ ����������
				this->_ratingInfo.grade = "�� �������";

				// ��������� � ������ ��������� ��������
				rating.push_back(this->_ratingInfo);
			}
	); // .. ������� ������� �� �������� ����������, ���� ��� ����

	// ��������� ��������� ������� ���������
	int counter = 1;
	for_each(_studentList._studentList.begin(), _studentList._studentList.end(),
		[&counter, &_studentList, group, this, rating](map<string, string> element) {
			// ������� ���� ��������� ������ ������ 
			if (element["group"] == group) {
				// �������� ��� ��������
				string studentName = this->getStudentNameByID(counter, _studentList);
				// ��������� � ������
				this->_ratingList[group].insert(make_pair(studentName, rating));
			}
			++counter;
		}
	);

	return true;
}

// ����� �������� ���� �� ������ ������ 
bool ratingList::empty() {
	return this->_ratingList.empty();
}
