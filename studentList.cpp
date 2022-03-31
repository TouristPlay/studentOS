#include "studentList.h"
#include "groupList.h"
#include "disciplineList.h"

// Метод считывание списка студентов с файла
bool studentList::read(groupList& _group, string filename) {
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
		copy(_student.begin() + positionOne + 1, _student.begin() + positionTwo, back_inserter(this->groupNumber));

		// Получаем номер группы
		copy(_student.begin() + positionTwo + 1, _student.end(), back_inserter(this->sex));

		//Проверка есть ли группа
		if (!this->checkGroup(this->groupNumber, _group)) {
			cout << " Не удалось добавить! Группы \"" << this->groupNumber << "\" не существует! " << endl;
			this->resetVariables(); // Обнуляем временные переменные
			continue;
		}

		// Вызываем метод для добавления студента в общий список
		this->append(this->name, this->surename, this->middlename, this->sex, this->groupNumber);
	}

	return true;
}

// Метод для записи списка студентов в файл
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
		for (student element : this->_studentList) {
			cout << element.getName() << " " << element.getGroup() << " " << element.getSex();
		}
		return true;
	}
	return false;
}

// Метод добавления студента в список
bool studentList::create(groupList& _group) {

	this->input();

	// Проверка есть ли группа
	if (!this->checkGroup(this->groupNumber, _group)) {
		cout << " Не удалось добавить! Группы \"" << this->groupNumber << "\" не существует! " << endl;
		this->resetVariables(); // Обнуляем временные переменные
		return false;
	}

	// Вызывам метод добавление студента
	this->append(this->name, this->surename, this->middlename, this->sex, this->groupNumber);

	return true;
}

// Метод изменения информации о студенте
bool studentList::update(unsigned id) {
	// Если пустой список и нет такого ID
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

// Метод удаление информации о студенте
bool studentList::remove(unsigned id) {

	// Если пустой список и нет такого ID
	if (empty() || !this->checkID(id)) {
		return false;
	}

	// Удаляем группу
	vector<student> ::iterator it = remove_if(this->_studentList.begin(), this->_studentList.end(),
		[id](student element) {
			return element.getID() == id;
		}
	);


	this->_studentList.erase(it, this->_studentList.end());


	return true;
}

// Метод вывода студентов в консоль
bool studentList::output() {

	// Если пустой список и нет такого ID
	if (empty()) {
		return false;
	}

	// Выводим список в консоль
	for (student element : this->_studentList) {
		cout << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << " " << element.getSex() << endl;
	}

	return true;
}

// Приватный метод для проверки пуст ли список студентов
bool studentList::empty() {
	return this->_studentList.empty();
}

// Метод проверяет есть ли такой ID
bool studentList::checkID(unsigned ID) {
	for (student element : this->_studentList) {
		if (element.getID() == ID) {
			return true;
		}
	}
	return false;
}

// Приватный метод для создание нового студента
void studentList::append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup) {

	student tempStudent(newName, newSurename, newMiddlename, newSex, newGroup);
	this->_studentList.push_back(tempStudent);
	this->resetVariables();

}

// Приватный метод обнуляет перменные класса
void studentList::resetVariables() {
	// Обнуляем временные перменные
	this->surename = "";
	this->name = "";
	this->middlename = "";
	this->groupNumber = "";
	this->sex = "";
}

// Приватный метод для проверки существует группа
bool studentList::checkGroup(string groupNumber, groupList _group) {

	for (group element : _group._groupList) {
		if (element.getGroup() == groupNumber) {
			return true;
		}
	}

	return false;
}

// Метод для ввода данных
void studentList::input() {
	// Просим ввести данные студента
	cout << " Введите полное имя студента [Ф И О]: ";
	cin >> this->surename >> this->name >> this->middlename;
	// Вводим пол студента
	cout << " Введие пол студента[муж/жен]: ";
	cin >> this->sex;
	// Вводим имя группы 
	cout << " Введите номер группы: ";
	cin >> this->groupNumber;
}

// Метод получает студента по ID
student& studentList::getStudentByID(unsigned ID) {
	for (auto& element : this->_studentList) {
		if (element.getID() == ID) {
			return element;
		}
	}
}

// Метод для получения студентов опредленной группы
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

// Метод для добавление оценки студенту
bool studentList::createRating(disciplineList &_discipline, groupList &_group, unsigned groupID) {


	// Группы не существует
	if (!_group.checkID(groupID)) {
		cout << " Группы c ID \"" << groupID << "\" не существует!" << endl;
		return false;
	}

	// Получаем группу
	group &current = _group.getGroupByID(groupID);

	// Если у группы не заданы дисциплины
	if (_group.empty()) {
		cout << " Дисциплины для сдачи не заданны у \"" << current.getGroup() << "\" группы!" << endl;
		return false;
	}


	// Выводим всех студентов опредленной группы
	if (!this->getGroupStudent(current.getGroup())) {
		cout << " Студентов в данной группе нет!" << endl;
		return false;
	}

	int studentID; // ID студента
	int disciplineID; // ID дисциплины

	cout << " Введите ID студента: ";
	cin >> studentID;

	// Проверяем есть ли такой ID в списке
	if (!this->checkID(studentID) || this->getStudentByID(studentID).getGroup() != current.getGroup()) {
		cout << " Студента с ID-" << studentID << " не существует" << endl;
		return false;
	}

	// Получаем студента 
	student& tempStudent = this->getStudentByID(studentID);

	// Выводим список дисциплин которая сдает группа
	current.getDiscipline();

	string status = "Y";

	do {

		string grade;

		cout << " Введите ID дисциплины: ";
		cin >> disciplineID;

		// Проверяем есть ли такой ID в списке
		if ((unsigned)disciplineID > current._session.size() || disciplineID < 1) {
			cout << " Дисциплины с ID-" << disciplineID << " не существует" << endl;
			return false;
		}

		// Вводим оценку дисциплины
		cout << " Введите оценку: ";
		cin >> grade;

		tempStudent._rating[disciplineID - 1].setGrade(grade);

		cout << " Вы хотите продолжить ввод? [Y/N]: ";
		cin >> status;

		// Если ввод неверный завершаем цикл
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");


	return true;
}

// Метод для получение оценок студента
bool studentList::getStudentGrade() {

	if (!this->output()) {
		cout << " Список студентов пуст!" << endl;;
		return false;
	}

	int studentID; // ID студента
	
	cout << " Введите ID студента: ";
	cin >> studentID;

	// Проверяем есть ли такой ID в списке
	if (!this->checkID(studentID)) {
		cout << " Студента с ID-" << studentID << " не существует" << endl;
		return false;
	}

	// Получаем студента 
	student &_student = this->getStudentByID(studentID);

	// Файловый поток
	ofstream file(_student.getName() + " Grade" + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	if (_student._rating.empty()) {
		cout << " Список оценок пуст" << endl;
		return false;
	}

	cout << " Оценки студента \"" << _student.getName() << "\" \"" << _student.getGroup() << "\" группы" << endl;
	file << " Оценки студента \"" << _student.getName() << "\" \"" << _student.getGroup() << "\" группы" << endl;

	int counter = 1;
	// Выводим оценки
	for (rating element : _student._rating) {
		cout << " \t #" << counter << " " << element.getName() << " - " << element.getGrade() << endl;
		file << " \t #" << counter << " " << element.getName() << " - " << element.getGrade() << endl;
		counter++;
	}

	return true;
}

// Метод для получения оценок факультета
bool studentList::getGroupGrade(unsigned groupID, groupList& _group) {
	if (!this->output()) {
		cout << " Список студентов пуст!";
		return false;
	}



	// Группы не существует
	if (!_group.checkID(groupID)) {
		cout << " Группы c ID \"" << groupID << "\" не существует!" << endl;
		return false;
	}


	// Получаем группу
	group _tempGroup = _group.getGroupByID(groupID);

	// Файловый поток
	ofstream file(_tempGroup.getGroup() + "group grade" + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	cout << " Оценки студентов \"" << _tempGroup.getGroup() << "\" группы" << endl;
	file << " Оценки студентов \"" << _tempGroup.getGroup() << "\" группы" << endl;

	cout << "\t " << setw(38) << "  ";
	file << "\t " << setw(38) << "  ";


	// Вывод предметов
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

	// Вывод списка оценок для студента
	for (student element : this->_studentList) {
		if (element.getGroup() == _tempGroup.getGroup()) {
			cout << "\t #" << element.getID() << " " << setw(35) << element.getName(); // Выводим имя
			file << "\t #" << element.getID() << " " << setw(35) << element.getName(); // Выводим имя

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

// Метод для получения списка студентов не сдавших сессию
bool studentList::getStudentNotPassSession() {

	if (this->empty()) {
		return false;
	}

	// Файловый поток
	ofstream file("studentNotPassSession.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	for (student element : this->_studentList) {
		for (rating item : element._rating) {
			if (item.getGrade() == "Не указано" || item.getGrade() == "незачет" || item.getGrade() == "2") {
				cout << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << endl;
				file << "\t #" << element.getID() << " " << element.getName() << " " << element.getGroup() << endl;
				break;
			}
		}
	}

	return true;
}

// Метод для получения среднего балла по группе 
bool studentList::getGroupAverage(unsigned groupID, groupList& _group) {

	if (this->empty()) {
		return false;
	}


	// Группы не существует
	if (!_group.checkID(groupID)) {
		cout << " Группы c ID \"" << groupID << "\" не существует!" << endl;
		return false;
	}

	

	// Получаем группу
	group _tempGroup = _group.getGroupByID(groupID);

	// Файловый поток
	ofstream file("GroupAverage-" + _tempGroup.getGroup() + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
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


	file << " Средняя оценка \"" << _tempGroup.getGroup() << "\" группы: ";
	cout << "\t Средняя оценка \"" << _tempGroup.getGroup() << "\" группы: ";

	if (average == 0) {
		return false;
		file << 0;
		cout << 0 << endl;
	}

	file << average / (double)counter;
	cout << average / (double)counter << endl;;

	return true;
}

// Метод для получения среднего балла по факультету
bool studentList::getFacultyAverage() {

	if (this->empty()) {
		return false;
	}

	// Файловый поток
	ofstream file("facultyAverage.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
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


	file << " Средняя оценка факультета: ";
	cout << "\t Средняя оценка факультета: ";

	file << average / (double)this->_studentList.size();
	cout << average / (double)this->_studentList.size() << endl;

	return true;
}
