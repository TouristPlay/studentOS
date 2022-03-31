#include "disciplineList.h"

#include "discipline.h"


// Публиный метод чтения списка дисциплин из файла
bool disciplineList::read(string filename) {
	// Создаем объект чтения файла
	ifstream file(filename + ".txt");

	if (!file) {
		cerr << "\n Не удалось открыть файл!" << endl;
		return false;
	}

	// Считывает имена дисциплина с файла
	while (!file.eof()) {
		// Считываем строку
		getline(file, this->disciplineName);

		// Проверка есть ли такая дисциплина
		if (this->checkDiscipline(this->disciplineName)) {
			cout << " Дисциплина \"" << this->disciplineName << "\" существует!" << endl;
			break;
		}

		discipline tempDiscipline(this->disciplineName);

		// Добавляем в список 
		this->_disciplineList.push_back(tempDiscipline);
	}

	return true;
}

// Публиный метод записи списка дисциплин в файл
bool disciplineList::write(string filename) {
	// Если список не пустой
	if (!this->empty()) {
		// Поток для записи 
		ofstream file(filename + ".txt");

		// Если файл не удалость открыть
		if (!file) {
			cerr << " \n Не удалось открыть файл!" << endl;
			return false;
		}

		for (auto element : this->_disciplineList) {
			file << element.getName() << endl;
		}

		return true;
	}
	return false;
}

// Публиный метод создает новую дисциплину
bool disciplineList::create() {
	// Просим ввести специальность
	cout << " Введите дисциплину: ";
	cin.ignore();
	getline(cin, this->disciplineName);

	// Проверка есть ли такая дисциплина
	if (this->checkDiscipline(this->disciplineName)) {
		cout << " Дисциплина \"" << this->disciplineName << "\" существует!" << endl;
		return false;
	}

	discipline tempDiscipline(this->disciplineName);

	// Добавляем в список 
	this->_disciplineList.push_back(tempDiscipline);

	return true;
}

// Публиный методизменения информации о группе
bool disciplineList::update(unsigned id) {
	if (empty() || !this->checkID(id)) {
		return false;
	}

	discipline &temp = this->getDisciplineByID(id);

	// Просим ввести специальность
	cout << " Введите дисциплину: ";
	cin.ignore();
	getline(cin, this->disciplineName);

	// Проверка есть ли такая дисциплина
	if (this->checkDiscipline(this->disciplineName)) {
		cout << " Дисциплина \"" << this->disciplineName << "\" существует!" << endl;
		return false;
	}

	temp.setName(this->disciplineName);

	return true;
}

// Публиный метод удаление информации о группе
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

// Публиный метод вывода списка групп в консоль
bool disciplineList::output() {
	if (this->empty()) {
		return false;
	}

	for (auto element : this->_disciplineList) {
		cout << "\t #" << element.getID() << " " << element.getName() << endl;
	}

	return true;
}

// Приватный метод для проверки пуст ли список дисциплин
bool disciplineList::empty() {
	return this->_disciplineList.empty();
}

// Метод получение дисциплина по ID
discipline &disciplineList::getDisciplineByID(unsigned ID) {
	for (auto &element : this->_disciplineList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// Метод для проверки существует ли такой ID
bool disciplineList::checkID(unsigned ID) {
	for (auto& element : this->_disciplineList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// Метод проверки, если ли уже такая дисциплина
bool disciplineList::checkDiscipline(string disciplineName) {
	for (auto element : this->_disciplineList) {
		if (element.getName() == disciplineName) {
			return true;
		}
	}
	return false;
}