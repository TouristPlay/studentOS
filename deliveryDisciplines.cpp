#include "deliveryDisciplines.h"
#include "disciplineList.h"


// ��������� ����� ���������� ���������� ��� �����
bool deliveryDisciplines::create(disciplineList _discipline, string groupNumber) {

	string status = "Y";

	_discipline.output();

	do {

		cout << " ������ \"" << groupNumber << "\"" << endl;

		// ������ ����������
		cout << " ������� ID ����������: ";
		cin >> this->disciplineId;

		// ��������� ����� ����������
		string disciplineName = _discipline._disciplineList[this->disciplineId - 1];

		// ���� ������ �� ��� ID
		if ((unsigned)this->disciplineId > _discipline._disciplineList.size() || this->disciplineId < 1) {
			cout << " ����� ���������� �� ����������!" << endl;
			return false;
		}
		// ���� ������� ���������� ������� ���� ��� � ������
		if (repeatInclude(disciplineName, groupNumber)) {
			cout << " ���������� \"" << disciplineName << "\" ��� ����������!" << endl;
			return false;
		}

		// ������ ��� �����
		cout << " ������� ��� �����: ";
		cin.ignore();
		getline(cin, this->deliveryType);
		// ������ ���� �����
		cout << " ������� ���� �����: ";
		getline(cin, this->deliveryDate);


		// �������� ����� ����������
		this->append(groupNumber, disciplineName, this->deliveryType, this->deliveryDate);

		cout << " �� ������ ���������� ����? [Y/N]: ";
		cin >> status;

		// ���� ���� �������� ��������� ����
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");

	return true;
};

// ��������� ����� ��������� ����������
bool deliveryDisciplines::update(string groupNumber) {

	// ���� ������ ����
	if (this->empty()) {
		cout << " ������ ����!" << endl;
		return false;
	}

	// ������� ������ ������ � ������
	this->element = this->_deliveryDisciplines.find(groupNumber);

	// ���� ������ �� ������
	if (this->element == this->_deliveryDisciplines.end()) {
		cout << " ������ \"" << groupNumber << "\" �� �������!" << endl;
		return false;
	}

	// ������� ������ ��������� ��� ������
	this->output(groupNumber);

	cout << " ������� ID ������ ��� ��������� : ";
	cin >> this->disciplineId;

	// ���� ������ �� ��� ID
	if ((unsigned)this->disciplineId > this->element->second.size() || this->disciplineId < 1) {
		cout << " ����� ������ �� ����������!" << endl;
		return false;
	}

	// ��������� ���������� � ��������� ����������
	cout << " ������� ��� �����: ";
	cin.ignore();
	getline(cin, element->second[disciplineId - 1].type);
	// ������ ���� �����
	cout << " ������� ���� �����: ";
	getline(cin, element->second[disciplineId - 1].date);

	return true;
};

// ��������� ����� �������� ���������� � ����������
bool deliveryDisciplines::remove(string groupNumber) {

	// ���� ������ ����
	if (this->empty()) {
		cout << " ������ ����!" << endl;
		return false;
	}


	// ������� ������ ������ � ������
	this->element = this->_deliveryDisciplines.find(groupNumber);

	// ���� ������ �� ������
	if (this->element == this->_deliveryDisciplines.end()) {
		cout << " ������ \"" << groupNumber << "\" �� �������!" << endl;
		return false;
	}

	// ������� ������ ��������� ��� ������
	this->output(groupNumber);

	cout << " ������� ID ������ ��� �������� : ";
	cin >> this->disciplineId;

	// ���� ������ �� ��� ID
	if ((unsigned)this->disciplineId > this->element->second.size() || this->disciplineId < 1) {
		cout << " ����� ������ �� ����������!" << endl;
		return false;
	}

	// ������� ������
	element->second.erase(element->second.begin() + disciplineId - 1);

	return true;
};

// ��������� ����� ������ ��������� ��� ������
bool deliveryDisciplines::output(string groupNumber) {

	// ���� ������ ����
	if (this->empty()) {
		return false;
	}

	// ������� ������ ������ � ������
	this->element = this->_deliveryDisciplines.find(groupNumber);

	int counter = 1;
	// ������� ����������
	for_each(this->element->second.begin(), this->element->second.end(), 
		[&counter](discipline item) {
			cout << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			++counter;
		}
	);

	return true;
};

// ��������� ����� ���������� ���������� � ������ �����
bool deliveryDisciplines::append(string newGroup, string newDisciplineName, string newDeliveryType, string newDeliveryDate) {
	

	// ��������� ���������
	disciplineInfo.name = newDisciplineName; // ��� ����������
	disciplineInfo.type = newDeliveryType; // ��� �����
	disciplineInfo.date = newDeliveryDate; // ���� �����


	// ��������� ���������� ��� ����� � ������
	this->_deliveryDisciplines[newGroup].push_back(disciplineInfo);

	// �������� ��� ���������
	this->resetVariabless();

	return true;
	
};

// ��������� ����� ��� ��������� ����������
void deliveryDisciplines::resetVariabless() {

	this->group = "";
	int disciplineId = 0;
	string deliveryType = "";
	string deliveryDate = "";
	this->disciplineInfo = { };
}

// ��������� ����� ��� �������� ������ �� ������
bool deliveryDisciplines::empty() {
	return this->_deliveryDisciplines.empty();
}

// ��������� ����� ��������� ��������� ���������� ����������
bool deliveryDisciplines::repeatInclude(string subjectName, string groupNumber) {

	// ������� ������ ������ � ������
	this->element = this->_deliveryDisciplines.find(groupNumber);

	bool flag = false;

	if (this->element == this->_deliveryDisciplines.end()) {
		return flag;
	}

	//���������� �� �������
	for_each(this->element->second.begin(), this->element->second.end(),
		[&flag, subjectName](discipline item) {
			if (item.name == subjectName) {
				flag = true;
			}
		}
	);

	return flag;
}