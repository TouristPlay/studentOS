#include "studentList.h"
#include "groupList.h"

// Публичный метод считывание списка студентов с файла
bool studentList::read(groupList _group, string filename) {
	// Создаем объект чтения файла
	ifstream file(filename + ".txt");

	// Содержит слово
	string _student;

	if (!file) {
		cerr << "\n Не удалось открыть файл!" << endl;
		return false;
	}

	// Считываем данные студента
	while (!file.eof()) {
		int positionOne, positionTwo = 0;
		getline(file, _student);


		// Получаем фамилию студента из строки
		positionOne = _student.find(" ");
		copy(_student.begin(), _student.begin() + positionOne, back_inserter(this->surename));

		// Получаем фамилию студента
		positionTwo = _student.find(" ", positionOne + 1);
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->name));

		// Получаем отчество студента
		positionOne = _student.find(" ", positionTwo + 1);
		copy(_student.begin() + positionTwo + 1, _student.begin() + positionOne, back_inserter(this->middlename));

		// Получаем номер группы
		positionTwo = _student.find(" ", positionOne + 1);
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->group));

		// Получаем номер группы
		copy(_student.begin() + positionTwo + 1, _student.end(), back_inserter(this->sex));

		//Проверка есть ли группа
		if (!this->checkGroup(this->group, _group)) {
			cout << " Не удалось добавить! Группы \"" << this->group << "\" не существует! " << endl;
			this->resetVariables(); // Обнуляем временные переменные
			continue;
		}

		// Вызываем метод для добавления студента в общий список
		this->append(this->name, this->surename, this->middlename, this->sex, this->group);
	}

	return true;
}

// Публичный метод для записи списка студентов в файл
bool studentList::write(string filename) {
	// Если список не пустой
	if (!this->empty()) {
		// Создаем объект записи файла
		ofstream file(filename + ".txt");

		// Если не смогли открыть файл
		if (!file) {
			cerr << "\n Не удалось открыть файл!" << endl;
			return false;
		}


		// Записываем слова в файл
		for_each(this->_studentList.begin(), this->_studentList.end(),
			[&file, this](map<string, string> element) {

				// Выводим строку в файл
				file << this->assemblyString(element) << endl;
			}
		);
		return true;
	}
	return false;
}

// Публичный метод добавления студента в список
bool studentList::create(groupList _group) {
	// Просим ввести данные студента
	cout << " Введите полное имя студента [Ф И О]: ";
	cin >> this->surename >> this->name >> this->middlename;
	// Вводим пол студента
	cout << " Введие пол студента[муж/жен]: ";
	cin >> this->sex;
	// Вводим имя группы 
	cout << " Введите номер группы: ";
	cin >> this->group;

	// Проверка есть ли группа
	if (!this->checkGroup(this->group, _group)) {
		cout << " Не удалось добавить! Группы \"" << this->group << "\" не существует! " << endl;
		this->resetVariables(); // Обнуляем временные переменные
		return false;
	}

	// Вызывам метод добавление студента
	this->append(this->name, this->surename, this->middlename, this->sex, this->group);

	return true;
}

// Публичный метод изменения информации о студенте
bool studentList::update(int id, groupList _group) {
	if (empty() || id > (int)this->_studentList.size() || id < 0) {
		return false;
	}
	// Выводим найденного студента
	map<string, string> element = this->_studentList[id - 1];
	cout << " Студент " << " \"#" << id << " " << this->assemblyString(element) << "\" найден" << endl;

	// Создаем нового студента
	if (!this->create(_group)) {
		return false;
	}

	// Меняем местами студентов
	swap(this->_studentList[id - 1], this->_studentList[this->_studentList.size() - 1]);

	// Удаляем студента в которого нужно внести поправки
	this->_studentList.erase(_studentList.end() - 1);

	return true;
}

// Публичный метод удаление информации о студенте
bool studentList::remove(int id) {
	if (empty() || id > (int)this->_studentList.size() || id < 0) {
		return false;
	}
	// Удаляем студента из списка
	this->_studentList.erase(_studentList.begin() + id - 1);
	return true;
}

// Публичный метод вывода студентов в консоль
bool studentList::output() {

	if (empty()) {
		return false;
	}

	// Счетчик
	int counter = 1;

	// Выводим список студентов в консоль
	for_each(this->_studentList.begin(), this->_studentList.end(),
		[this, &counter](map<string, string> element) {
			// Выводим строку в консоль
			cout << "\t #" << counter << " " << this->assemblyString(element) << endl;
			// Увеличиваем счетчик
			++counter;
		}
	);
	return true;
}

// Приватный метод для создание нового студента
void studentList::append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup) {

	// Создаем врменный контейнер map
	map<string, string> _newStudent;

	// Заполняем контейнер данными
	_newStudent["name"] = newName; // Имя
	_newStudent["surename"] = newSurename; // Фамилия
	_newStudent["middlename"] = newMiddlename; // Отчество
	_newStudent["sex"] = newSex; // пол
	_newStudent["group"] = newGroup; // Отчество

	// Обнуляем временные переменные 
	this->resetVariables();

	// Добавляем студента в общий список
	this->_studentList.push_back(_newStudent);
}

// Приватный метод обнуляет перменные класса
void studentList::resetVariables() {
	// Обнуляем временные перменные
	this->surename = "";
	this->name = "";
	this->middlename = "";
	this->group = "";
	this->sex = "";
}

// Приватный метод собирает строку 
string studentList::assemblyString(map<string, string> element) {

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

// Приватный метод для проверки пуст ли список студентов
bool studentList::empty() {
	return this->_studentList.empty();
}

// Приватный метод для проверки существует группа
bool studentList::checkGroup(string groupNumber, groupList _group) {
	// Флаг поиска
	bool flag = false;
	// Перебираем массив групп
	for_each(_group._groupList.begin(), _group._groupList.end(),
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
