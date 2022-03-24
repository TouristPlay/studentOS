#include "ratingList.h"

#include "studentList.h"
#include "deliveryDisciplines.h"
#include "groupList.h"


// Метод для добавления оценок студенту
bool ratingList::create(string group, deliveryDisciplines _disciplineList, studentList _studentList, groupList _group) {

	
	// Группы не существует
	if (!_group.checkGroup(group)) {
		cout << " Группы \"" << group << "\" не существует!" << endl;
		return false;
	}

	// Если у группы не заданы дисциплины
	if (_disciplineList._deliveryDisciplines.find(group) == _disciplineList._deliveryDisciplines.end()) {
		cout << " Дисциплины для сдачи не заданны у \"" << group << "\" группы!" << endl;
		return false;
	}

	// Заполняем список дисциплин для каждого студента 
	insertAllStudent(group, _disciplineList, _studentList);

	// Выводим всех студентов опредленной группы
	if (!this->findStudent(group, _studentList)) {
		cout << " Студентов в данной группе нет!" << endl;
		return false;
	}

	int studentID; // ID студента
	int disciplineID; // ID дисциплины

	cout << " Введите ID студента: ";
	cin >> studentID;

	// Проверяем есть ли такой ID в списке
	if ((unsigned)studentID > _studentList._studentList.size() || studentID < 1 || _studentList._studentList[studentID - 1]["group"] != group) {
		cout << " Студента с ID-" << studentID << " не существует" << endl;
		return false;
	}


	// Выводим список дисциплин которая сдает группа
	_disciplineList.output(group);

	string status = "Y";
	vector <rating> _rating; // Содержит дисциплину с оценкой студента

	do {

		cout << " Введите ID дисциплины: ";
		cin >> disciplineID;

		// Проверяем есть ли такой ID в списке
		if ((unsigned)disciplineID > _disciplineList._deliveryDisciplines[group].size() || disciplineID < 1) {
			cout << " Дисциплины с ID-" << disciplineID << " не существует" << endl;
			return false;
		}

		// Получаем имя дисциплины
		string disciplineName = _disciplineList._deliveryDisciplines[group][disciplineID - 1].name;

		// Имя студента
		string studentName = this->getStudentNameByID(studentID, _studentList);


		map<string, map<string, vector<rating>>> ::iterator it = this->_ratingList.find(group);
		map<string, vector<rating>>::iterator element = it->second.begin();

		// Пробегаемся по всему списку студентов группы
		for (; element != it->second.end(); ++element) {
			if (studentName == element->first) {
				// Итератор на список дисциплин
				vector <rating> :: iterator item = element->second.begin();
				// Ищем нужную дисциплину
				for (; item != element->second.end(); ++item) {
						if (item->discipline == disciplineName) {
						// Вводим оценку дисциплины
						cout << " Введите оценку: ";
						cin >> item->grade;
					}
				}
			}
		}


		cout << " Вы хотите продолжить ввод? [Y/N]: ";
		cin >> status;

		// Добавляем в массив дисциплин студента
		_rating.push_back(this->_ratingInfo);

		// Если ввод неверный завершаем цикл
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");


	return true;
}

// Метод для поиска студентов опредленной группы
bool ratingList::findStudent(string group, studentList _studentList) {
	int counter = 1;
	bool flag = false;
	for_each(_studentList._studentList.begin(), _studentList._studentList.end(), 
		[&counter, &_studentList, group, &flag](map<string, string> element) {
			// Выводим всех студентов данной группы 
			if (element["group"] == group) {
				cout << " #" << counter << _studentList.assemblyString(element) << endl;
				flag = true;
			}
			++counter;
		}
	);

	return flag;
}

// Метод получения имени студента по ID 
string ratingList::getStudentNameByID(int id, studentList _studentList) {
	// Данные студента
	map<string, string> element = _studentList._studentList[id - 1];

	return element["surename"] + " " + element["name"] + " " + element["middlename"];
}	

// Метод добавляет всех студентов и дисциплины в список
bool ratingList::insertAllStudent(string group, deliveryDisciplines _disciplineList, studentList _studentList) {
	
	vector <rating> rating; // Содержит дисциплину с оценкой студента

	// Заполняем дисциплины
	for_each(_disciplineList._deliveryDisciplines[group].begin(), _disciplineList._deliveryDisciplines[group].end(), 
			[this, &rating](deliveryDisciplines::discipline element) {
				// Имя дисциплины
				this->_ratingInfo.discipline = element.name;
				// Вводим оценку дисциплины
				this->_ratingInfo.grade = "Не указано";

				// Добавляем в массив дисциплин студента
				rating.push_back(this->_ratingInfo);
			}
	); // .. проверу сделать не изменять дисциплину, если она есть

	// Заполняем студентов списком предметов
	int counter = 1;
	for_each(_studentList._studentList.begin(), _studentList._studentList.end(),
		[&counter, &_studentList, group, this, rating](map<string, string> element) {
			// Выводим всех студентов данной группы 
			if (element["group"] == group) {
				// Получаем имя студента
				string studentName = this->getStudentNameByID(counter, _studentList);
				// Добавляем в список
				this->_ratingList[group].insert(make_pair(studentName, rating));
			}
			++counter;
		}
	);

	return true;
}

// Метод проверки пуст ли списко оценок 
bool ratingList::empty() {
	return this->_ratingList.empty();
}
