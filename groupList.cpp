#include "groupList.h"
#include "studentList.h"
#include "disciplineList.h"


// Метод считывание списка групп
bool groupList::read(string filename) {
	// Создаем объект чтения файла
	ifstream file(filename + ".txt");

	// Содержит слово
	string _group;

	if (!file) {
		cerr << " Не удалось открыть файл!" << endl;
		return false;
	}

	// Считываем данные студента
	while (!file.eof()) {
		int positionOne, positionTwo = 0;
		getline(file, _group);

		// Получаем номер группы
		positionOne = _group.find(" ", positionTwo + 1);
		copy(_group.begin(), _group.begin() + positionOne, back_inserter(this->groupNumber));

		// Получаем курс
		positionTwo = _group.find(" ", positionOne + 1);
		copy(_group.begin() + positionOne + 1, _group.begin() + positionTwo, back_inserter(this->course));

		// Получаем специальность
		copy(_group.begin() + positionTwo + 1, _group.end(), back_inserter(this->speciality));

		// Проверка есть ли такая группа
		if (this->checkGroup(this->groupNumber)) {
			cout << " Не удалось добавить! Группа \"" << this->groupNumber << "\" существует!" << endl;
			this->resetVariables(); // Обнуляем временные переменные;
			continue;
		}

		// Добавляем группы в список
		append(this->groupNumber, this->course, this->speciality);
	}


	return true;
}

// Метод для записи списка студентов в файл
bool groupList::write(string filename) {
	// Если список не пустой
	if (!this->empty()) {
		// Создаем объект записи файла
		ofstream file(filename + ".txt");

		// Если не смогли открыть файл
		if (!file) {
			cerr << " Не удалось открыть файл!" << endl;
			return false;
		}
		
		// Записываем в файл
		for (group element : this->_groupList) {
			file << element.getGroup() << " " << element.getCourse() << " " << element.getSpeciality();
		}

		return true;
	}
	return false;
}

// Метод добавления группы в список
bool groupList::create() {

	this->input();

	// Проверка есть ли такая группа
	if (this->checkGroup(this->groupNumber)) {
		cout << " Не удалось добавить! Группа \"" << this->groupNumber << "\" существует!" << endl;
		this->resetVariables(); // Обнуляем временные переменные;
		return false;
	}

	// Добавляем группы в список
	append(this->groupNumber, this->course, this->speciality);

	return true;
}

// Метод изменения информации о группе
bool groupList::update(unsigned id) {

	// Если пустой список или ID не существует
	if (empty() || !this->checkID(id)) {
		return false;
	}

	group &element = this->getGroupByID(id);

	cout << "Группа \"#"
		<< element.getID() << " "
		<< element.getGroup() << " "
		<< element.getCourse() << " "
		<< element.getSpeciality() << "\" найдена" << endl;;

	// Вводим новые данные
	this->input();

	// Заменяем элемент
	element.setCourse(this->course);
	element.setGroup(this->groupNumber);
	element.setSpeciality(this->speciality);

	
	return true;
}

// Метод удаление информации о группе
bool groupList::remove(unsigned id, studentList& _student) {


	// Если пустой список или ID не существует
	if (empty() || !this->checkID(id)) {
		return false;
	}

	group tempGroup = this->getGroupByID(id);

	// Проверяем, есть ли студенты в группу
	if (this->checkStudent(tempGroup.getGroup(), _student)) {
		cout << " Не удалось удалить! В \"" << tempGroup.getGroup() << "\" группе  есть студенты" << endl;
		return false;
	}


	// Удаляем группу
	vector<group> :: iterator it = remove_if(this->_groupList.begin(), this->_groupList.end(), 
			[id](group element) {
				return element.getID() == id;
			}
		);


	this->_groupList.erase(it, this->_groupList.end());

	return true;
}

// Метод вывода списка групп в консоль
bool groupList::output() {

	if (empty()) {
		return false;
	}

	// Выводим группу
	for (group element : this->_groupList) {
		cout << "\t #"
			<< element.getID() << " "
			<< element.getGroup() << " "
			<< element.getCourse() << " "
			<< element.getSpeciality() << endl;
	}

	return true;
}

// Приватный метод для проверки пуст ли список групп
bool groupList::empty() {
	return this->_groupList.empty();
}

// Приватный метод для создание новой группы
void groupList::append(string newGroup, string newCourse, string newSpeciality) {
	group tempGroup(newGroup, newCourse, newSpeciality);
	this->_groupList.push_back(tempGroup);
	this->resetVariables();
}

// Приватный метод обнуляет перменные класса
void groupList::resetVariables() {
	// Обнуляем временные перменные
	this->course = "";
	this->groupNumber = "";
	this->speciality = "";
}

// Метод для считывания строки
void groupList::input() {
	// Просим ввести специальность
	cout << "\t Введите специальность: ";
	cin.ignore();
	getline(cin, this->speciality);
	// Вводим номер группы
	cout << "\t Введите номер группы: ";
	cin >> this->groupNumber;
	// Вводим курс
	cout << "\t Введите курс: ";
	cin >> this->course;
}

// Приватный метод для проверки существует ли группа
bool groupList::checkGroup(string groupNumber) {

	for (group element : this->_groupList) {
		if (element.getGroup() == groupNumber) {
			return true;
		}
	}

	return false;
}

// Приватный метод проверяет, есть ли студент в группе
bool groupList::checkStudent(string group, studentList &_student) {

	for (student element : _student._studentList) {
		if (element.getGroup() == group) {
			return true;
		}
	}

	return false;
}

// Метод получает группу по ID
group &groupList::getGroupByID(unsigned ID) {
	
	// Ищем группу
	for (auto &element : this->_groupList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// Метод проверяет есть ли такой ID
bool groupList::checkID(unsigned ID) {
	for (group element : this->_groupList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// Метод добавления дисциплины для сдачи
bool groupList::createDiscipline(disciplineList& _discipline, studentList &_student, unsigned ID) {
	string status = "Y";

	// Если ввели не тот ID
	if (!this->checkID(ID)) {
		return false;
	}

	// Находим группу 
	group &currentGroup = this->getGroupByID(ID);

	_discipline.output();

	unsigned id = 0;

	do {

		// Вспомогательные перменные
		string type;
		string date;

		// Вводим дисциплину
		cout << " Введите ID дисциплины: ";
		cin >> id;

		// Если выбрал не тот ID
		if (!_discipline.checkID(id)) {
			cout << " Такой дисциплины не существует!" << endl;
			return false;
		}

		// Получаем дисциплину
		discipline& currentDiscipline = _discipline.getDisciplineByID(id);

		// Если дисциплина уже добавлена
		for (session element : currentGroup._session) {
			if (element.getDisciplineName() == currentDiscipline.getName()) {
				cout << " Дисциплина \"" << currentDiscipline.getName() << "\" уще существует!" << endl;
				return false;
			}
		}

		// Вводим тип сдачи
		cout << " Введите тип сдачи: ";
		cin.ignore();
		getline(cin, type);
		// Вводим дату сдачи
		cout << " Введите дату сдачи: ";
		getline(cin, date);


		// Создаем предмет для сессии
		session tempSession(type, date, currentDiscipline);


		//	Добавляем предметы
		rating _tempRating(currentDiscipline, "Не указано");

		for (auto &element : _student._studentList) {
			if (element.getGroup() == currentGroup.getGroup()) {
				element._rating.push_back(_tempRating);
			}
		}


		// Вызываем метод добавления
		currentGroup._session.push_back(tempSession);

		cout << " Вы хотите продолжить ввод? [Y/N]: ";
		cin >> status;

		// Если ввод неверный завершаем цикл
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");

	return true;
}

// Метод для обновления предмета для сдачи
bool groupList::updateDiscipline(unsigned ID) {

	// Если ввели не тот ID
	if (!this->checkID(ID)) {
		return false;
	}

	// Находим группу 
	group &currentGroup = this->getGroupByID(ID);

	currentGroup.getDiscipline();

	// Если списко пуст
	if (currentGroup._session.empty()) {
		cout << " Список пуст!" << endl;
		return false;
	}

	// Вспомогательные перменные
	string type;
	string date;
	unsigned id;

	// Вводим дисциплину
	cout << " Введите ID дисциплины: ";
	cin >> id;

	// Если выбрал не тот ID
	if (id > currentGroup._session.size() || id < 0) {
		cout << " Такой дисциплины не существует!" << endl;
		return false;
	}

	// Вводим тип сдачи
	cout << " Введите тип сдачи: ";
	cin.ignore();
	getline(cin, type);
	// Вводим дату сдачи
	cout << " Введите дату сдачи: ";
	getline(cin, date);

	currentGroup._session[id - 1].setDate(date);
	currentGroup._session[id - 1].setType(type);

	return true;

}

// Метод для удаления предмета для сдачи
bool groupList::removeDiscipline(unsigned ID) {

	// Если ввели не тот ID
	if (!this->checkID(ID)) {
		return false;
	}

	// Находим группу 
	group &currentGroup = this->getGroupByID(ID);

	currentGroup.getDiscipline();

	// Если списко пуст
	if (currentGroup._session.empty()) {
		cout << " Список пуст!" << endl;
		return false;
	}

	unsigned id;

	// Вводим дисциплину
	cout << " Введите ID дисциплины: ";
	cin >> id;

	// Если выбрал не тот ID
	if (id > currentGroup._session.size() || id < 0) {
		cout << " Такой дисциплины не существует!" << endl;
		return false;
	}


	currentGroup._session.erase(currentGroup._session.begin() + id - 1);

	return true;
}

// Метод для получения списка дисциплин
bool groupList::getGroupDiscipline(unsigned ID) {

	// Если ввели не тот ID
	if (!this->checkID(ID)) {
		return false;
	}

	group& temp = this->getGroupByID(ID);

	// Файловый поток
	ofstream file("GroupDiscipline-" + temp.getGroup() + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	// Если списко пуст
	if (temp._session.empty()) {
		cout << " Список пуст!" << endl;
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

// Метод вывода дисциплин всего факультета
bool groupList::getFacultyDescipline() {
	// Если списко пуст
	if (this->empty()) {
		return false;
	}

	// Файловый поток
	ofstream file("FacultyDiscipline.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	// Сортируем группы по возрастанию
	sort(this->_groupList.begin(), this->_groupList.end(), 
			[](group &a, group &b) -> bool {
				return a.getGroup() < b.getGroup();
			}
		);

	// Выводим дисциплины
	for (group element : this->_groupList) {

		cout << " Дисциплины \"" << element.getGroup() << "\" группы для сдачи" << endl;
		file << " Дисциплины \"" << element.getGroup() << "\" группы для сдачи" << endl;

		if (element._session.empty()) {
			cout << "\t #0 | Дисциплины для сдачи не указаны" << endl;
			file << "\t #0 | Дисциплины для сдачи не указаны" << endl;
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