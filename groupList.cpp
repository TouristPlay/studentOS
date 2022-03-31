#include "groupList.h"
#include "studentList.h"
#include "disciplineList.h"


// ����� ���������� ������ �����
bool groupList::read(string filename) {
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
		copy(_group.begin(), _group.begin() + positionOne, back_inserter(this->groupNumber));

		// �������� ����
		positionTwo = _group.find(" ", positionOne + 1);
		copy(_group.begin() + positionOne + 1, _group.begin() + positionTwo, back_inserter(this->course));

		// �������� �������������
		copy(_group.begin() + positionTwo + 1, _group.end(), back_inserter(this->speciality));

		// �������� ���� �� ����� ������
		if (this->checkGroup(this->groupNumber)) {
			cout << " �� ������� ��������! ������ \"" << this->groupNumber << "\" ����������!" << endl;
			this->resetVariables(); // �������� ��������� ����������;
			continue;
		}

		// ��������� ������ � ������
		append(this->groupNumber, this->course, this->speciality);
	}


	return true;
}

// ����� ��� ������ ������ ��������� � ����
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
		
		// ���������� � ����
		for (group element : this->_groupList) {
			file << element.getGroup() << " " << element.getCourse() << " " << element.getSpeciality();
		}

		return true;
	}
	return false;
}

// ����� ���������� ������ � ������
bool groupList::create() {

	this->input();

	// �������� ���� �� ����� ������
	if (this->checkGroup(this->groupNumber)) {
		cout << " �� ������� ��������! ������ \"" << this->groupNumber << "\" ����������!" << endl;
		this->resetVariables(); // �������� ��������� ����������;
		return false;
	}

	// ��������� ������ � ������
	append(this->groupNumber, this->course, this->speciality);

	return true;
}

// ����� ��������� ���������� � ������
bool groupList::update(unsigned id) {

	// ���� ������ ������ ��� ID �� ����������
	if (empty() || !this->checkID(id)) {
		return false;
	}

	group &element = this->getGroupByID(id);

	cout << "������ \"#"
		<< element.getID() << " "
		<< element.getGroup() << " "
		<< element.getCourse() << " "
		<< element.getSpeciality() << "\" �������" << endl;;

	// ������ ����� ������
	this->input();

	// �������� �������
	element.setCourse(this->course);
	element.setGroup(this->groupNumber);
	element.setSpeciality(this->speciality);

	
	return true;
}

// ����� �������� ���������� � ������
bool groupList::remove(unsigned id, studentList& _student) {


	// ���� ������ ������ ��� ID �� ����������
	if (empty() || !this->checkID(id)) {
		return false;
	}

	group tempGroup = this->getGroupByID(id);

	// ���������, ���� �� �������� � ������
	if (this->checkStudent(tempGroup.getGroup(), _student)) {
		cout << " �� ������� �������! � \"" << tempGroup.getGroup() << "\" ������  ���� ��������" << endl;
		return false;
	}


	// ������� ������
	vector<group> :: iterator it = remove_if(this->_groupList.begin(), this->_groupList.end(), 
			[id](group element) {
				return element.getID() == id;
			}
		);


	this->_groupList.erase(it, this->_groupList.end());

	return true;
}

// ����� ������ ������ ����� � �������
bool groupList::output() {

	if (empty()) {
		return false;
	}

	// ������� ������
	for (group element : this->_groupList) {
		cout << "\t #"
			<< element.getID() << " "
			<< element.getGroup() << " "
			<< element.getCourse() << " "
			<< element.getSpeciality() << endl;
	}

	return true;
}

// ��������� ����� ��� �������� ���� �� ������ �����
bool groupList::empty() {
	return this->_groupList.empty();
}

// ��������� ����� ��� �������� ����� ������
void groupList::append(string newGroup, string newCourse, string newSpeciality) {
	group tempGroup(newGroup, newCourse, newSpeciality);
	this->_groupList.push_back(tempGroup);
	this->resetVariables();
}

// ��������� ����� �������� ��������� ������
void groupList::resetVariables() {
	// �������� ��������� ���������
	this->course = "";
	this->groupNumber = "";
	this->speciality = "";
}

// ����� ��� ���������� ������
void groupList::input() {
	// ������ ������ �������������
	cout << "\t ������� �������������: ";
	cin.ignore();
	getline(cin, this->speciality);
	// ������ ����� ������
	cout << "\t ������� ����� ������: ";
	cin >> this->groupNumber;
	// ������ ����
	cout << "\t ������� ����: ";
	cin >> this->course;
}

// ��������� ����� ��� �������� ���������� �� ������
bool groupList::checkGroup(string groupNumber) {

	for (group element : this->_groupList) {
		if (element.getGroup() == groupNumber) {
			return true;
		}
	}

	return false;
}

// ��������� ����� ���������, ���� �� ������� � ������
bool groupList::checkStudent(string group, studentList &_student) {

	for (student element : _student._studentList) {
		if (element.getGroup() == group) {
			return true;
		}
	}

	return false;
}

// ����� �������� ������ �� ID
group &groupList::getGroupByID(unsigned ID) {
	
	// ���� ������
	for (auto &element : this->_groupList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// ����� ��������� ���� �� ����� ID
bool groupList::checkID(unsigned ID) {
	for (group element : this->_groupList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// ����� ���������� ���������� ��� �����
bool groupList::createDiscipline(disciplineList& _discipline, studentList &_student, unsigned ID) {
	string status = "Y";

	// ���� ����� �� ��� ID
	if (!this->checkID(ID)) {
		return false;
	}

	// ������� ������ 
	group &currentGroup = this->getGroupByID(ID);

	_discipline.output();

	unsigned id = 0;

	do {

		// ��������������� ���������
		string type;
		string date;

		// ������ ����������
		cout << " ������� ID ����������: ";
		cin >> id;

		// ���� ������ �� ��� ID
		if (!_discipline.checkID(id)) {
			cout << " ����� ���������� �� ����������!" << endl;
			return false;
		}

		// �������� ����������
		discipline& currentDiscipline = _discipline.getDisciplineByID(id);

		// ���� ���������� ��� ���������
		for (session element : currentGroup._session) {
			if (element.getDisciplineName() == currentDiscipline.getName()) {
				cout << " ���������� \"" << currentDiscipline.getName() << "\" ��� ����������!" << endl;
				return false;
			}
		}

		// ������ ��� �����
		cout << " ������� ��� �����: ";
		cin.ignore();
		getline(cin, type);
		// ������ ���� �����
		cout << " ������� ���� �����: ";
		getline(cin, date);


		// ������� ������� ��� ������
		session tempSession(type, date, currentDiscipline);


		//	��������� ��������
		rating _tempRating(currentDiscipline, "�� �������");

		for (auto &element : _student._studentList) {
			if (element.getGroup() == currentGroup.getGroup()) {
				element._rating.push_back(_tempRating);
			}
		}


		// �������� ����� ����������
		currentGroup._session.push_back(tempSession);

		cout << " �� ������ ���������� ����? [Y/N]: ";
		cin >> status;

		// ���� ���� �������� ��������� ����
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");

	return true;
}

// ����� ��� ���������� �������� ��� �����
bool groupList::updateDiscipline(unsigned ID) {

	// ���� ����� �� ��� ID
	if (!this->checkID(ID)) {
		return false;
	}

	// ������� ������ 
	group &currentGroup = this->getGroupByID(ID);

	currentGroup.getDiscipline();

	// ���� ������ ����
	if (currentGroup._session.empty()) {
		cout << " ������ ����!" << endl;
		return false;
	}

	// ��������������� ���������
	string type;
	string date;
	unsigned id;

	// ������ ����������
	cout << " ������� ID ����������: ";
	cin >> id;

	// ���� ������ �� ��� ID
	if (id > currentGroup._session.size() || id < 0) {
		cout << " ����� ���������� �� ����������!" << endl;
		return false;
	}

	// ������ ��� �����
	cout << " ������� ��� �����: ";
	cin.ignore();
	getline(cin, type);
	// ������ ���� �����
	cout << " ������� ���� �����: ";
	getline(cin, date);

	currentGroup._session[id - 1].setDate(date);
	currentGroup._session[id - 1].setType(type);

	return true;

}

// ����� ��� �������� �������� ��� �����
bool groupList::removeDiscipline(unsigned ID) {

	// ���� ����� �� ��� ID
	if (!this->checkID(ID)) {
		return false;
	}

	// ������� ������ 
	group &currentGroup = this->getGroupByID(ID);

	currentGroup.getDiscipline();

	// ���� ������ ����
	if (currentGroup._session.empty()) {
		cout << " ������ ����!" << endl;
		return false;
	}

	unsigned id;

	// ������ ����������
	cout << " ������� ID ����������: ";
	cin >> id;

	// ���� ������ �� ��� ID
	if (id > currentGroup._session.size() || id < 0) {
		cout << " ����� ���������� �� ����������!" << endl;
		return false;
	}


	currentGroup._session.erase(currentGroup._session.begin() + id - 1);

	return true;
}

// ����� ��� ��������� ������ ���������
bool groupList::getGroupDiscipline(unsigned ID) {

	// ���� ����� �� ��� ID
	if (!this->checkID(ID)) {
		return false;
	}

	group& temp = this->getGroupByID(ID);

	// �������� �����
	ofstream file("GroupDiscipline-" + temp.getGroup() + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	// ���� ������ ����
	if (temp._session.empty()) {
		cout << " ������ ����!" << endl;
		return false;
	}

	int counter = 1;

	for (auto element : temp._session) {
		cout << left << "\t #" << counter << " | "
			<< setw(25) << element.getDisciplineName() << " | "
			<< setw(15) << element.getType() << " | "
			<< element.getDate() << endl;
		file << left << "\t #" << counter << " | "
			<< setw(25) << element.getDisciplineName() << " | "
			<< setw(15) << element.getType() << " | "
			<< element.getDate() << endl;
		counter++;
	}
	return true;
	return true;
}

// ����� ������ ��������� ����� ����������
bool groupList::getFacultyDescipline() {
	// ���� ������ ����
	if (this->empty()) {
		return false;
	}

	// �������� �����
	ofstream file("FacultyDiscipline.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	// ��������� ������ �� �����������
	sort(this->_groupList.begin(), this->_groupList.end(), 
			[](group &a, group &b) -> bool {
				return a.getGroup() < b.getGroup();
			}
		);

	// ������� ����������
	for (group element : this->_groupList) {

		cout << " ���������� \"" << element.getGroup() << "\" ������ ��� �����" << endl;
		file << " ���������� \"" << element.getGroup() << "\" ������ ��� �����" << endl;

		if (element._session.empty()) {
			cout << "\t #0 | ���������� ��� ����� �� �������" << endl;
			file << "\t #0 | ���������� ��� ����� �� �������" << endl;
		}

		int counter = 1;

		for (session item : element._session) {
			cout << left << "\t #" << counter << " | "
				<< setw(25) << item.getDisciplineName() << " | "
				<< setw(15) << item.getType() << " | "
				<< item.getDate() << endl;
			file << left << "\t #" << counter << " | "
				<< setw(25) << item.getDisciplineName() << " | "
				<< setw(15) << item.getType() << " | "
				<< item.getDate() << endl;
			counter++;
		}

		cout << endl;
	}

	return true;
}