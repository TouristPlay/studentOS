#include "groupList.h"
#include "studentList.h"

// ��������� ����� ���������� ������ �����
bool groupList::read(studentList _student, string filename) {
	// ������� ������ ������ �����
	ifstream file(filename + ".txt");

	// �������� �����
	string _group;

	if (!file) {
		cerr << " �� ������� ������� ����!" << endl;
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

		// �������� ���� �� ����� ������
		if (checkGroup(this->group)) {
			cout << " �� ������� ��������! ������ \"" << this->group << "\" ����������!" << endl;
			this->resetVariables(); // �������� ��������� ����������;
			continue;
		}

		// ��������� ������ � ������
		append(this->group, this->course, this->speciality);
	}


	return true;
}

// ��������� ����� ��� ������ ������ ��������� � ����
bool groupList::write(string filename) {
	// ���� ������ �� ������
	if (!this->empty()) {
		// ������� ������ ������ �����
		ofstream file(filename + ".txt");

		// ���� �� ������ ������� ����
		if (!file) {
			cerr << " �� ������� ������� ����!" << endl;
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
bool groupList::create(studentList _student) {

	this->input();

	// �������� ���� �� ����� ������
	if (checkGroup(this->group)) {
		cout << " �� ������� ��������! ������ \"" << this->group << "\" ����������!" << endl;
		this->resetVariables(); // �������� ��������� ����������;
		return false;
	}

	// ��������� ������ � ������
	append(this->group, this->course, this->speciality);

	return true;
}

// ��������� ����� ��������� ���������� � ������
bool groupList::update(int id, studentList _student) {
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}
	// ������� ��������� ������
	map<string, string> element = this->_groupList[id - 1];
	cout << " ������ " << " \"#" << id << " " << this->assemblyString(element) << "\" �������" << endl;

	// �������� ������ �� ���������
	string temp = element["group"];

	this->input();

	if (this->group != temp) {
		// �������� ���� �� ����� ������
		if (checkGroup(this->group)) {
			cout << " �� ������� ��������! ������ \"" << this->group << "\" ����������!" << endl;
			this->resetVariables(); // �������� ��������� ����������;
			return false;
		} 
	}


	element["group"] = this->group; // ������
	element["course"] = this->course; // ����
	element["speciality"] = this->speciality; // �������������


	this->_groupList[id - 1] = element;

	return true;
}

// ��������� ����� �������� ���������� � ������
bool groupList::remove(int id, studentList _student) {

	// ���� ������ ���� ��� ��� ����� ������
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}

	// ���������, ���� �� �������� � ������
	if (this->checkStudent(_groupList[id - 1]["group"], _student)) {
		cout << " �� ������� �������! � \"" << _groupList[id - 1]["group"] << "\" ������  ���� ��������" << endl;
		return false;
	}


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
			cout << "\t #" << counter << " " << this->assemblyString(element) << endl;
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

// ��������� ����� ���������, ���� �� ������� � ������
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
			}
		}
	);

	return flag;
}

// ��������� ����� ��� �������� ���������� �� ������
bool groupList::checkGroup(string groupNumber) {
	// ���� ������
	bool flag = false;
	// ���������� ������ �����
	for_each(this->_groupList.begin(), this->_groupList.end(),
		[groupNumber, &flag](map<string, string> element) {
			// ���������� �������� �� ��������� �������
			map<string, string> ::iterator it = element.find("group");
			if (it->second == groupNumber) {
				flag = true;
			}
		}
	);

	return flag;
}
	
// ����� ��� ���������� ������
void groupList::input() {
	// ������ ������ �������������
	cout << "\t ������� �������������: ";
	cin.ignore();
	getline(cin, this->speciality);
	// ������ ����� ������
	cout << "\t ������� ����� ������: ";
	cin >> this->group;
	// ������ ����
	cout << "\t ������� ����: ";
	cin >> this->course;
}