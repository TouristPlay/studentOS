#include "disciplineList.h"


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
		// ��������� � ������ 
		this->_disciplineList.push_back(this->disciplineName);
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

		// ���������� � ����
		for_each(this->_disciplineList.begin(), this->_disciplineList.end(),
			[&file](string element) {
				file << element << endl;
			}
		);

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


	//--�������� ���� �� ������� � ������--///

	// ��������� ������ � ������
	this->_disciplineList.push_back(this->disciplineName);

	return true;
}

// �������� ����� ��������� ���������� � ������
bool disciplineList::update(int id) {
	if (empty() || id > (int)this->_disciplineList.size() || id < 0) {
		return false;
	}
	// ������� ��������� ����������
	cout << " ���������� " << " \"#" << id << " " << _disciplineList[id - 1] << "\" �������" << endl;

	// ������� ����� ������
	this->create();

	// ������ ������� ������
	swap(this->_disciplineList[id - 1], this->_disciplineList[this->_disciplineList.size() - 1]);

	// ������� ������ � �������� ����� ������ ��������
	this->_disciplineList.erase(_disciplineList.end() - 1);

	return true;
}

// �������� ����� �������� ���������� � ������
bool disciplineList::remove(int id) {
	if (empty() || id > (int)this->_disciplineList.size() || id < 0) {
		return false;
	}
	// ������� ������ �� ������
	this->_disciplineList.erase(_disciplineList.begin() + id - 1);
	return true;
}

// �������� ����� ������ ������ ����� � �������
bool disciplineList::output() {

	if (empty()) {
		return false;
	}

	// �������
	int counter = 1;

	// ������� ������ ���������
	for_each(this->_disciplineList.begin(), this->_disciplineList.end(),
		[&counter](string element) {
			// ������� ������ � �������
			cout << "\t #" << counter << " " << element << endl;
			// ����������� �������
			++counter;
		}
	);
	return true;
}


// ��������� ����� ��� �������� ���� �� ������ ���������
bool disciplineList::empty() {
	return this->_disciplineList.empty();
}
