#include "studentList.h"
#include "groupList.h"

// ��������� ����� ���������� ������ ��������� � �����
bool studentList::read(groupList _group, string filename) {
	// ������� ������ ������ �����
	ifstream file(filename + ".txt");

	// �������� �����
	string _student;

	if (!file) {
		cerr << "\n �� ������� ������� ����!" << endl;
		return false;
	}

	// ��������� ������ ��������
	while (!file.eof()) {
		int positionOne, positionTwo = 0;
		getline(file, _student);


		// �������� ������� �������� �� ������
		positionOne = _student.find(" ");
		copy(_student.begin(), _student.begin() + positionOne, back_inserter(this->surename));

		// �������� ������� ��������
		positionTwo = _student.find(" ", positionOne + 1);
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->name));

		// �������� �������� ��������
		positionOne = _student.find(" ", positionTwo + 1);
		copy(_student.begin() + positionTwo + 1, _student.begin() + positionOne, back_inserter(this->middlename));

		// �������� ����� ������
		positionTwo = _student.find(" ", positionOne + 1);
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->group));

		// �������� ����� ������
		copy(_student.begin() + positionTwo + 1, _student.end(), back_inserter(this->sex));

		//�������� ���� �� ������
		if (!this->checkGroup(this->group, _group)) {
			cout << " �� ������� ��������! ������ \"" << this->group << "\" �� ����������! " << endl;
			this->resetVariables(); // �������� ��������� ����������
			continue;
		}

		// �������� ����� ��� ���������� �������� � ����� ������
		this->append(this->name, this->surename, this->middlename, this->sex, this->group);
	}

	return true;
}

// ��������� ����� ��� ������ ������ ��������� � ����
bool studentList::write(string filename) {
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
		for_each(this->_studentList.begin(), this->_studentList.end(),
			[&file, this](map<string, string> element) {

				// ������� ������ � ����
				file << this->assemblyString(element) << endl;
			}
		);
		return true;
	}
	return false;
}

// ��������� ����� ���������� �������� � ������
bool studentList::create(groupList _group) {
	// ������ ������ ������ ��������
	cout << " ������� ������ ��� �������� [� � �]: ";
	cin >> this->surename >> this->name >> this->middlename;
	// ������ ��� ��������
	cout << " ������ ��� ��������[���/���]: ";
	cin >> this->sex;
	// ������ ��� ������ 
	cout << " ������� ����� ������: ";
	cin >> this->group;

	// �������� ���� �� ������
	if (!this->checkGroup(this->group, _group)) {
		cout << " �� ������� ��������! ������ \"" << this->group << "\" �� ����������! " << endl;
		this->resetVariables(); // �������� ��������� ����������
		return false;
	}

	// ������� ����� ���������� ��������
	this->append(this->name, this->surename, this->middlename, this->sex, this->group);

	return true;
}

// ��������� ����� ��������� ���������� � ��������
bool studentList::update(int id, groupList _group) {
	if (empty() || id > (int)this->_studentList.size() || id < 0) {
		return false;
	}
	// ������� ���������� ��������
	map<string, string> element = this->_studentList[id - 1];
	cout << " ������� " << " \"#" << id << " " << this->assemblyString(element) << "\" ������" << endl;

	// ������� ������ ��������
	if (!this->create(_group)) {
		return false;
	}

	// ������ ������� ���������
	swap(this->_studentList[id - 1], this->_studentList[this->_studentList.size() - 1]);

	// ������� �������� � �������� ����� ������ ��������
	this->_studentList.erase(_studentList.end() - 1);

	return true;
}

// ��������� ����� �������� ���������� � ��������
bool studentList::remove(int id) {
	if (empty() || id > (int)this->_studentList.size() || id < 0) {
		return false;
	}
	// ������� �������� �� ������
	this->_studentList.erase(_studentList.begin() + id - 1);
	return true;
}

// ��������� ����� ������ ��������� � �������
bool studentList::output() {

	if (empty()) {
		return false;
	}

	// �������
	int counter = 1;

	// ������� ������ ��������� � �������
	for_each(this->_studentList.begin(), this->_studentList.end(),
		[this, &counter](map<string, string> element) {
			// ������� ������ � �������
			cout << "\t #" << counter << " " << this->assemblyString(element) << endl;
			// ����������� �������
			++counter;
		}
	);
	return true;
}

// ��������� ����� ��� �������� ������ ��������
void studentList::append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup) {

	// ������� �������� ��������� map
	map<string, string> _newStudent;

	// ��������� ��������� �������
	_newStudent["name"] = newName; // ���
	_newStudent["surename"] = newSurename; // �������
	_newStudent["middlename"] = newMiddlename; // ��������
	_newStudent["sex"] = newSex; // ���
	_newStudent["group"] = newGroup; // ��������

	// �������� ��������� ���������� 
	this->resetVariables();

	// ��������� �������� � ����� ������
	this->_studentList.push_back(_newStudent);
}

// ��������� ����� �������� ��������� ������
void studentList::resetVariables() {
	// �������� ��������� ���������
	this->surename = "";
	this->name = "";
	this->middlename = "";
	this->group = "";
	this->sex = "";
}

// ��������� ����� �������� ������ 
string studentList::assemblyString(map<string, string> element) {

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

// ��������� ����� ��� �������� ���� �� ������ ���������
bool studentList::empty() {
	return this->_studentList.empty();
}

// ��������� ����� ��� �������� ���������� ������
bool studentList::checkGroup(string groupNumber, groupList _group) {
	// ���� ������
	bool flag = false;
	// ���������� ������ �����
	for_each(_group._groupList.begin(), _group._groupList.end(),
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
