#include "studentList.h"
#include "groupList.h"
#include "disciplineList.h"

// ����� ���������� ������ ��������� � �����
bool studentList::read(groupList& _group, string filename) {
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
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->groupNumber));

		// �������� ����� ������
		copy(_student.begin() + positionTwo + 1, _student.end(), back_inserter(this->sex));

		//�������� ���� �� ������
		if (!this->checkGroup(this->groupNumber, _group)) {
			cout << " �� ������� ��������! ������ \"" << this->groupNumber << "\" �� ����������! " << endl;
			this->resetVariables(); // �������� ��������� ����������
			continue;
		}

		// �������� ����� ��� ���������� �������� � ����� ������
		this->append(this->name, this->surename, this->middlename, this->sex, this->groupNumber);
	}

	return true;
}

// ����� ��� ������ ������ ��������� � ����
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
		for (student element : this->_studentList) {
			cout << element.getName() << " " << element.getGroup() << " " << element.getSex();
		}
		return true;
	}
	return false;
}

// ����� ���������� �������� � ������
bool studentList::create(groupList& _group) {

	this->input();

	// �������� ���� �� ������
	if (!this->checkGroup(this->groupNumber, _group)) {
		cout << " �� ������� ��������! ������ \"" << this->groupNumber << "\" �� ����������! " << endl;
		this->resetVariables(); // �������� ��������� ����������
		return false;
	}

	// ������� ����� ���������� ��������
	this->append(this->name, this->surename, this->middlename, this->sex, this->groupNumber);

	return true;
}

// ����� ��������� ���������� � ��������
bool studentList::update(unsigned id) {
	// ���� ������ ������ � ��� ������ ID
	if (empty() || !this->checkID(id)) {
		return false;
	}

	student &tempStudent = this->getStudentByID(id);

	this->input();

	tempStudent.changeName(this->name, this->surename, this->middlename);
	tempStudent.changeGroup(this->groupNumber);
	tempStudent.changeSex(this->sex);

	return true;
}

// ����� �������� ���������� � ��������
bool studentList::remove(unsigned id) {

	// ���� ������ ������ � ��� ������ ID
	if (empty() || !this->checkID(id)) {
		return false;
	}

	// ������� ������
	vector<student> ::iterator it = remove_if(this->_studentList.begin(), this->_studentList.end(),
		[id](student element) {
			return element.getID() == id;
		}
	);


	this->_studentList.erase(it, this->_studentList.end());


	return true;
}

// ����� ������ ��������� � �������
bool studentList::output() {

	// ���� ������ ������ � ��� ������ ID
	if (empty()) {
		return false;
	}

	// ������� ������ � �������
	for (student element : this->_studentList) {
		cout << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << " " << element.getSex() << endl;
	}

	return true;
}

// ��������� ����� ��� �������� ���� �� ������ ���������
bool studentList::empty() {
	return this->_studentList.empty();
}

// ����� ��������� ���� �� ����� ID
bool studentList::checkID(unsigned ID) {
	for (student element : this->_studentList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// ��������� ����� ��� �������� ������ ��������
void studentList::append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup) {

	student tempStudent(newName, newSurename, newMiddlename, newSex, newGroup);
	this->_studentList.push_back(tempStudent);
	this->resetVariables();

}

// ��������� ����� �������� ��������� ������
void studentList::resetVariables() {
	// �������� ��������� ���������
	this->surename = "";
	this->name = "";
	this->middlename = "";
	this->groupNumber = "";
	this->sex = "";
}

// ��������� ����� ��� �������� ���������� ������
bool studentList::checkGroup(string groupNumber, groupList _group) {

	for (group element : _group._groupList) {
		if (element.getGroup() == groupNumber) {
			return true;
		}
	}

	return false;
}

// ����� ��� ����� ������
void studentList::input() {
	// ������ ������ ������ ��������
	cout << " ������� ������ ��� �������� [� � �]: ";
	cin >> this->surename >> this->name >> this->middlename;
	// ������ ��� ��������
	cout << " ������ ��� ��������[���/���]: ";
	cin >> this->sex;
	// ������ ��� ������ 
	cout << " ������� ����� ������: ";
	cin >> this->groupNumber;
}

// ����� �������� �������� �� ID
student& studentList::getStudentByID(unsigned ID) {
	for (auto& element : this->_studentList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// ����� ��� ��������� ��������� ����������� ������
bool studentList::getGroupStudent(string groupName) {
	bool flag = false;

	for (student element : this->_studentList) {
		if (element.getGroup() == groupName) {
			cout << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << " " << element.getSex() << endl;
			flag = true;
		}
	}

	return flag;
}

// ����� ��� ���������� ������ ��������
bool studentList::createRating(disciplineList &_discipline, groupList &_group, unsigned groupID) {


	// ������ �� ����������
	if (!_group.checkID(groupID)) {
		cout << " ������ c ID \"" << groupID << "\" �� ����������!" << endl;
		return false;
	}

	// �������� ������
	group &current = _group.getGroupByID(groupID);

	// ���� � ������ �� ������ ����������
	if (_group.empty()) {
		cout << " ���������� ��� ����� �� ������� � \"" << current.getGroup() << "\" ������!" << endl;
		return false;
	}


	// ������� ���� ��������� ����������� ������
	if (!this->getGroupStudent(current.getGroup())) {
		cout << " ��������� � ������ ������ ���!" << endl;
		return false;
	}

	int studentID; // ID ��������
	int disciplineID; // ID ����������

	cout << " ������� ID ��������: ";
	cin >> studentID;

	// ��������� ���� �� ����� ID � ������
	if (!this->checkID(studentID) || this->getStudentByID(studentID).getGroup() != current.getGroup()) {
		cout << " �������� � ID-" << studentID << " �� ����������" << endl;
		return false;
	}

	// �������� �������� 
	student& tempStudent = this->getStudentByID(studentID);

	// ������� ������ ��������� ������� ����� ������
	current.getDiscipline();

	string status = "Y";

	do {

		string grade;

		cout << " ������� ID ����������: ";
		cin >> disciplineID;

		// ��������� ���� �� ����� ID � ������
		if ((unsigned)disciplineID > current._session.size() || disciplineID < 1) {
			cout << " ���������� � ID-" << disciplineID << " �� ����������" << endl;
			return false;
		}

		// ������ ������ ����������
		cout << " ������� ������: ";
		cin >> grade;

		tempStudent._rating[disciplineID - 1].setGrade(grade);

		cout << " �� ������ ���������� ����? [Y/N]: ";
		cin >> status;

		// ���� ���� �������� ��������� ����
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");


	return true;
}

// ����� ��� ��������� ������ ��������
bool studentList::getStudentGrade() {

	if (!this->output()) {
		cout << " ������ ��������� ����!" << endl;;
		return false;
	}

	int studentID; // ID ��������
	
	cout << " ������� ID ��������: ";
	cin >> studentID;

	// ��������� ���� �� ����� ID � ������
	if (!this->checkID(studentID)) {
		cout << " �������� � ID-" << studentID << " �� ����������" << endl;
		return false;
	}

	// �������� �������� 
	student &_student = this->getStudentByID(studentID);

	// �������� �����
	ofstream file(_student.getName() + " Grade" + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	if (_student._rating.empty()) {
		cout << " ������ ������ ����" << endl;
		return false;
	}

	cout << " ������ �������� \"" << _student.getName() << "\" \"" << _student.getGroup() << "\" ������" << endl;
	file << " ������ �������� \"" << _student.getName() << "\" \"" << _student.getGroup() << "\" ������" << endl;

	int counter = 1;
	// ������� ������
	for (rating element : _student._rating) {
		cout << " \t #" << counter << " " << element.getName() << " - " << element.getGrade() << endl;
		file << " \t #" << counter << " " << element.getName() << " - " << element.getGrade() << endl;
		counter++;
	}

	return true;
}

// ����� ��� ��������� ������ ����������
bool studentList::getGroupGrade(unsigned groupID, groupList& _group) {
	if (!this->output()) {
		cout << " ������ ��������� ����!";
		return false;
	}



	// ������ �� ����������
	if (!_group.checkID(groupID)) {
		cout << " ������ c ID \"" << groupID << "\" �� ����������!" << endl;
		return false;
	}


	// �������� ������
	group _tempGroup = _group.getGroupByID(groupID);

	// �������� �����
	ofstream file(_tempGroup.getGroup() + "group grade" + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	cout << " ������ ��������� \"" << _tempGroup.getGroup() << "\" ������" << endl;
	file << " ������ ��������� \"" << _tempGroup.getGroup() << "\" ������" << endl;

	cout << "\t " << setw(38) << "  ";
	file << "\t " << setw(38) << "  ";


	// ����� ���������
	for (group item : _group._groupList) {
		if (item.getGroup() == _tempGroup.getGroup()) {
			if (item._session.empty()) {
				return false;
			}
			for (session element : item._session) {
				file << left << setw(25) << element.getDisciplineName();
				cout << left << setw(25) << element.getDisciplineName();
			}
		}
	}

	cout << endl;
	file << endl;

	// ����� ������ ������ ��� ��������
	for (student element : this->_studentList) {
		if (element.getGroup() == _tempGroup.getGroup()) {
			cout << "\t #" << element.getID() << " " << setw(35) << element.getName(); // ������� ���
			file << "\t #" << element.getID() << " " << setw(35) << element.getName(); // ������� ���

			for (rating item : element._rating) {
				cout << left << setw(25) << item.getGrade();
				file << left << setw(25) << item.getGrade();
			}

			cout << endl;
			file << endl;
		}
	}


	return true;
} 

// ����� ��� ��������� ������ ��������� �� ������� ������
bool studentList::getStudentNotPassSession() {

	if (this->empty()) {
		return false;
	}

	// �������� �����
	ofstream file("studentNotPassSession.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	for (student element : this->_studentList) {
		for (rating item : element._rating) {
			if (item.getGrade() == "�� �������" || item.getGrade() == "�������" || item.getGrade() == "2") {
				cout << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << endl;
				file << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << endl;
				break;
			}
		}
	}

	return true;
}

// ����� ��� ��������� �������� ����� �� ������ 
bool studentList::getGroupAverage(unsigned groupID, groupList& _group) {

	if (this->empty()) {
		return false;
	}


	// ������ �� ����������
	if (!_group.checkID(groupID)) {
		cout << " ������ c ID \"" << groupID << "\" �� ����������!" << endl;
		return false;
	}

	

	// �������� ������
	group _tempGroup = _group.getGroupByID(groupID);

	// �������� �����
	ofstream file("GroupAverage-" + _tempGroup.getGroup() + ".txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	double average = 0;
	int counter = 0;


	for (student element : this->_studentList) {
		if (element.getGroup() == _tempGroup.getGroup()) {
			for (rating item : element._rating) {
				if (item.getGrade() == "2" || item.getGrade() == "3" || item.getGrade() == "4" || item.getGrade() == "5") {
					average += stoi(item.getGrade());
				}
			}
			counter++;
		}
	}


	file << " ������� ������ \"" << _tempGroup.getGroup() << "\" ������: ";
	cout << "\t ������� ������ \"" << _tempGroup.getGroup() << "\" ������: ";

	if (average == 0) {
		return false;
		file << 0;
		cout << 0 << endl;
	}

	file << average / (double)counter;
	cout << average / (double)counter << endl;;

	return true;
}

// ����� ��� ��������� �������� ����� �� ����������
bool studentList::getFacultyAverage() {

	if (this->empty()) {
		return false;
	}

	// �������� �����
	ofstream file("facultyAverage.txt");

	// ���� ���� �� ������� �������
	if (!file) {
		cerr << " ������! �� ������� ������� ���� ��� ������!" << endl;
		return false;
	}

	double average = 0;


	for (student element : this->_studentList) {
		for (rating item : element._rating) {
			if (item.getGrade() == "2" || item.getGrade() == "3" || item.getGrade() == "4" || item.getGrade() == "5") {
				average += stoi(item.getGrade());
			}
		}
	}

	if (average == 0) {
		return false;
		file << 0;
		cout << 0 << endl;
	}


	file << " ������� ������ ����������: ";
	cout << "\t ������� ������ ����������: ";

	file << average / (double)this->_studentList.size();
	cout << average / (double)this->_studentList.size() << endl;

	return true;
}
