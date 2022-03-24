#include "groupList.h"
#include "studentList.h"

// Публичный метод считывание списка групп
bool groupList::read(studentList _student, string filename) {
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
		copy(_group.begin(), _group.begin() + positionOne, back_inserter(this->group));

		// Получаем курс
		positionTwo = _group.find(" ", positionOne + 1);
		copy(_group.begin() + positionOne + 1, _group.begin() + positionTwo, back_inserter(this->course));

		// Получаем специальность
		copy(_group.begin() + positionTwo + 1, _group.end(), back_inserter(this->speciality));

		// Проверка есть ли такая группа
		if (checkGroup(this->group)) {
			cout << " Не удалось добавить! Группа \"" << this->group << "\" существует!" << endl;
			this->resetVariables(); // Обнуляем временные переменные;
			continue;
		}

		// Добавляем группы в список
		append(this->group, this->course, this->speciality);
	}


	return true;
}

// Публичный метод для записи списка студентов в файл
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


		// Записываем слова в файл
		for_each(this->_groupList.begin(), this->_groupList.end(),
			[&file, this](map<string, string> element) {
				// Выводим строку в файл
				file << this->assemblyString(element) << endl;
			}
		);
		return true;
	}
	return false;
}

// Публичный метод добавления группы в список
bool groupList::create(studentList _student) {

	this->input();

	// Проверка есть ли такая группа
	if (checkGroup(this->group)) {
		cout << " Не удалось добавить! Группа \"" << this->group << "\" существует!" << endl;
		this->resetVariables(); // Обнуляем временные переменные;
		return false;
	}

	// Добавляем группы в список
	append(this->group, this->course, this->speciality);

	return true;
}

// Публичный метод изменения информации о группе
bool groupList::update(int id, studentList _student) {
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}
	// Выводим найденную группу
	map<string, string> element = this->_groupList[id - 1];
	cout << " Группа " << " \"#" << id << " " << this->assemblyString(element) << "\" найдена" << endl;

	// Содержит данные до изменения
	string temp = element["group"];

	this->input();

	if (this->group != temp) {
		// Проверка есть ли такая группа
		if (checkGroup(this->group)) {
			cout << " Не удалось добавить! Группа \"" << this->group << "\" существует!" << endl;
			this->resetVariables(); // Обнуляем временные переменные;
			return false;
		} 
	}


	element["group"] = this->group; // Группы
	element["course"] = this->course; // Курс
	element["speciality"] = this->speciality; // Специальность


	this->_groupList[id - 1] = element;

	return true;
}

// Публичный метод удаление информации о группе
bool groupList::remove(int id, studentList _student) {

	// Если список пуст или нет такой группы
	if (empty() || id > (int)this->_groupList.size() || id < 0) {
		return false;
	}

	// Проверяем, есть ли студенты в группу
	if (this->checkStudent(_groupList[id - 1]["group"], _student)) {
		cout << " Не удалось удалить! В \"" << _groupList[id - 1]["group"] << "\" группе  есть студенты" << endl;
		return false;
	}


	// Удаляем группу из списка
	this->_groupList.erase(_groupList.begin() + id - 1);
	return true;
}

// Публичный метод вывода списка групп в консоль
bool groupList::output() {

	if (empty()) {
		return false;
	}

	// Счетчик
	int counter = 1;

	// Выводим список групп
	for_each(this->_groupList.begin(), this->_groupList.end(),
		[this, &counter](map<string, string> element) {
			// Выводим строку в консоль
			cout << "\t #" << counter << " " << this->assemblyString(element) << endl;
			// Увеличиваем счетчик
			++counter;
		}
	);
	return true;
}


// Приватный метод для проверки пуст ли список групп
bool groupList::empty() {
	return this->_groupList.empty();
}

// Приватный метод для создание новой группы
void groupList::append(string newGroup, string newCourse, string newSpeciality) {

	// Создаем врменный контейнер map
	map<string, string> _newGroup;

	// Заполняем контейнер данными
	_newGroup["group"] = newGroup; // Группы
	_newGroup["course"] = newCourse; // Курс
	_newGroup["speciality"] = newSpeciality; // Специальность

	// Обнуляем перменные класса
	this->resetVariables();

	// Добавляем студента в общий список
	this->_groupList.push_back(_newGroup);
}

// Приватный метод обнуляет перменные класса
void groupList::resetVariables() {
	// Обнуляем временные перменные
	this->course = "";
	this->group = "";
	this->speciality = "";
}

// Приватный метод собирает строку 
string groupList::assemblyString(map<string, string> element) {

	string data;

	// Создаем строку последовательно соединяя 
	for (auto& tempItem : this->writeQueue) {
		for (auto& itemElement : element) {
			if (tempItem == itemElement.first) {
				data += " " + itemElement.second; // Складываем строки
			}
		}
	}
	return data; // Возвращаем собранную строку
}

// Приватный метод проверяет, есть ли студент в группе
bool groupList::checkStudent(string group, studentList _student) {
	// Флаг поиска
	bool flag = false;

	// Перебираем массив всех студентов
	for_each(_student._studentList.begin(), _student._studentList.end(),
		[group, &flag](map<string, string> element) {
			// Итератор на элемент вектора
			map <string, string> ::iterator it = element.find("group");
			// Если нашли студента в группе
			if (it->second == group) {
				flag = true;
			}
		}
	);

	return flag;
}

// Приватный метод для проверки существует ли группа
bool groupList::checkGroup(string groupNumber) {
	// Флаг поиска
	bool flag = false;
	// Перебираем массив групп
	for_each(this->_groupList.begin(), this->_groupList.end(),
		[groupNumber, &flag](map<string, string> element) {
			// Возвращаем итератор на найденный элемент
			map<string, string> ::iterator it = element.find("group");
			if (it->second == groupNumber) {
				flag = true;
			}
		}
	);

	return flag;
}
	
// Метод для считывания строки
void groupList::input() {
	// Просим ввести специальность
	cout << "\t Введите специальность: ";
	cin.ignore();
	getline(cin, this->speciality);
	// Вводим номер группы
	cout << "\t Введите номер группы: ";
	cin >> this->group;
	// Вводим курс
	cout << "\t Введите курс: ";
	cin >> this->course;
}