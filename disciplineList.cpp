#include "disciplineList.h"

#include "discipline.h"


// �������� ����� ������ ������ ��������� �� �����
bool disciplineList::read(string filename) {
	// ������� ������ ������ �����
	ifstream file(filename + ".txt");

	if (!file) {
		cerr << "\n �� ������� ������� ����!" << endl;
		return false;
	}

	// ��������� ����� ���������� � �����
	while (!file.eof()) {
		// ��������� ������
		getline(file, this->disciplineName);

		// �������� ���� �� ����� ����������
		if (this->checkDiscipline(this->disciplineName)) {
			cout << " ���������� \"" << this->disciplineName << "\" ����������!" << endl;
			break;
		}

		discipline tempDiscipline(this->disciplineName);

		// ��������� � ������ 
		this->_disciplineList.push_back(tempDiscipline);
	}

	return true;
}

// �������� ����� ������ ������ ��������� � ����
bool disciplineList::write(string filename) {
	// ���� ������ �� ������
	if (!this->empty()) {
		// ����� ��� ������ 
		ofstream file(filename + ".txt");

		// ���� ���� �� �������� �������
		if (!file) {
			cerr << " \n �� ������� ������� ����!" << endl;
			return false;
		}

		for (auto element : this->_disciplineList) {
			file << element.getName() << endl;
		}

		return true;
	}
	return false;
}

// �������� ����� ������� ����� ����������
bool disciplineList::create() {
	// ������ ������ �������������
	cout << " ������� ����������: ";
	cin.ignore();
	getline(cin, this->disciplineName);

	// �������� ���� �� ����� ����������
	if (this->checkDiscipline(this->disciplineName)) {
		cout << " ���������� \"" << this->disciplineName << "\" ����������!" << endl;
		return false;
	}

	discipline tempDiscipline(this->disciplineName);

	// ��������� � ������ 
	this->_disciplineList.push_back(tempDiscipline);

	return true;
}

// �������� �������������� ���������� � ������
bool disciplineList::update(unsigned id) {
	if (empty() || !this->checkID(id)) {
		return false;
	}

	discipline &temp = this->getDisciplineByID(id);

	// ������ ������ �������������
	cout << " ������� ����������: ";
	cin.ignore();
	getline(cin, this->disciplineName);

	// �������� ���� �� ����� ����������
	if (this->checkDiscipline(this->disciplineName)) {
		cout << " ���������� \"" << this->disciplineName << "\" ����������!" << endl;
		return false;
	}

	temp.setName(this->disciplineName);

	return true;
}

// �������� ����� �������� ���������� � ������
bool disciplineList::remove(unsigned id) {

	if (empty() || !this->checkID(id)) {
		return false;
	}

	vector<discipline> ::iterator it = remove_if(this->_disciplineList.begin(), this->_disciplineList.end(), 
		[id](discipline element) {
			return element.getID() == id;
		}
	);

	this->_disciplineList.erase(it, this->_disciplineList.end());

	return true;
}

// �������� ����� ������ ������ ����� � �������
bool disciplineList::output() {
	if (this->empty()) {
		return false;
	}

	for (auto element : this->_disciplineList) {
		cout << "\t #" << element.getID() << " " << element.getName() << endl;
	}

	return true;
}

// ��������� ����� ��� �������� ���� �� ������ ���������
bool disciplineList::empty() {
	return this->_disciplineList.empty();
}

// ����� ��������� ���������� �� ID
discipline &disciplineList::getDisciplineByID(unsigned ID) {
	for (auto &element : this->_disciplineList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// ����� ��� �������� ���������� �� ����� ID
bool disciplineList::checkID(unsigned ID) {
	for (auto& element : this->_disciplineList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// ����� ��������, ���� �� ��� ����� ����������
bool disciplineList::checkDiscipline(string disciplineName) {
	for (auto element : this->_disciplineList) {
		if (element.getName() == disciplineName) {
			return true;
		}
	}
	return false;
}