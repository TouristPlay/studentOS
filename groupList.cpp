#include "groupList.h"


// ��������� ����� ���������� ������ �����
bool groupList::read(string filename = "group") {
	// ������� ������ ������ �����
	ifstream file(filename + ".txt");

	// �������� �����
	string _group;

	if (!file) {
		cerr << "\n �� ������� ������� ����!" << endl;
		return false;
	}

	// ��������� ������ ��������
	while (!file.eof()) {
		int positionOne, positionTwo = 0;
		getline(file, _group);

		// �������� ����� ������
		positionOne = _group.find(" ", positionTwo + 1);
		copy(_group.begin(), _group.begin() + positionOne, back_inserter(this->group));

		// �������� ����
		positionTwo = _group.find(" ", positionOne + 1);
		copy(_group.begin() + positionOne + 1, _group.begin() + positionTwo, back_inserter(this->course));

		// �������� �������������
		copy(_group.begin() + positionTwo + 1, _group.end(), back_inserter(this->speciality));

		// ��������� ������ � ������
		append(this->group, this->course, this->speciality);
	}


	return true;
}

// ��������� ����� ��� ������ ������ ��������� � ����
bool groupList::write(string filename = "newGroup") {
	// ���� ������ �� ������
	if (!this->empty()) {
		// ������� ������ ������ �����
		ofstream file(filename + ".txt");

		// ���� �� ������ ������� ����
		if (!file) {
			cerr << "\n �� ������� ������� ����!" << endl;
			return false;
		}


		// ���������� ����� � ����
		for_each(this->_groupList.begin(), this->_groupList.end(),
			[&file, this](map<string, string> element) {
				// ������� ������ � ����
				file << this->assemblyString(element) << endl;
			}
		);
		return true;
	}
	return false;
}

// ��������� ����� ���������� ������ � ������
bool groupList::create() {
	// ������ ������ �������������
	cout << " ������� �������������: ";
	cin.ignore();
	getline(cin, this->speciality);
	// ������ ����� ������
	cout << " ������� ����� ������: ";
	cin >> this->group;
	// ������ ����
	cout << " ������� ����: ";
	cin >> this->course;

	//--�������� ���� �� ������� � ������--///


	// ��������� ������ � ������
	append(this->group, this->course, this->speciality);

	return true;
}

// ��������� ����� ��������� ���������� � ������
bool groupList::update(int id) {
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}
	// ������� ��������� ������
	map<string, string> element = this->_groupList[id - 1];
	cout << " ������ " << " \"#" << id << " " << this->assemblyString(element) << "\" �������" << endl;

	// ������� ����� ������
	this->create();

	// ������ ������� ������
	swap(this->_groupList[id - 1], this->_groupList[this->_groupList.size() - 1]);

	// ������� ������ � �������� ����� ������ ��������
	this->_groupList.erase(_groupList.end() - 1);

	return true;
}

// ��������� ����� �������� ���������� � ������
bool groupList::remove(int id, studentList _student) {

	// ���� ������ ���� ��� ��� ����� ������
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}


	// �������� �� ������
	vector <map<string, string>> ::iterator it = _groupList.begin() + id - 1;

	/*if (this->checkStudent()) {

	}*/



	// ������� ������ �� ������
	this->_groupList.erase(_groupList.begin() + id - 1);
	return true;
}

// ��������� ����� ������ ������ ����� � �������
bool groupList::output() {

	if (empty()) {
		return false;
	}

	// �������
	int counter = 1;

	// ������� ������ �����
	for_each(this->_groupList.begin(), this->_groupList.end(),
		[this, &counter](map<string, string> element) {
			// ������� ������ � �������
			cout << " #" << counter << " " << this->assemblyString(element) << endl;
			// ����������� �������
			++counter;
		}
	);
	return true;
}


// ��������� ����� ��� �������� ���� �� ������ �����
bool groupList::empty() {
	return this->_groupList.empty();
}

// ��������� ����� ��� �������� ����� ������
void groupList::append(string newGroup, string newCourse, string newSpeciality) {

	// ������� �������� ��������� map
	map<string, string> _newGroup;

	// ��������� ��������� �������
	_newGroup["group"] = newGroup; // ������
	_newGroup["course"] = newCourse; // ����
	_newGroup["speciality"] = newSpeciality; // �������������

	// �������� ��������� ������
	this->resetVariables();

	// ��������� �������� � ����� ������
	this->_groupList.push_back(_newGroup);
}

// ��������� ����� �������� ��������� ������
void groupList::resetVariables() {
	// �������� ��������� ���������
	this->course = "";
	this->group = "";
	this->speciality = "";
}

// ��������� ����� �������� ������ 
string groupList::assemblyString(map<string, string> element) {

	string data;

	// ������� ������ ��������������� �������� 
	for (auto& tempItem : this->writeQueue) {
		for (auto& itemElement : element) {
			if (tempItem == itemElement.first) {
				data += " " + itemElement.second; // ���������� ������
			}
		}
	}
	return data; // ���������� ��������� ������
}

// ��������� ����� ���������, ���� ������� � ������
bool groupList::checkStudent(string group, studentList _student) {
	// ���� ������
	bool flag = false;

	// ���������� ������ ���� ���������
	for_each(_student._studentList.begin(), _student._studentList.end(),
		[group, &flag](map<string, string> element) {
			// �������� �� ������� �������
			map <string, string> ::iterator it = element.find("group");
			// ���� ����� �������� � ������
			if (it->second == group) {
				flag = true;
				return;
			}
		}
	);

	return flag;
}
	