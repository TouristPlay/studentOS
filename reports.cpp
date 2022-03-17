#include "reports.h"

#include "deliveryDisciplines.h"
#include "ratingList.h"
#include "studentList.h"
#include "groupList.h"


// Метод вывода дисциплин для сдачи конкретной группы
bool reports::getGroupDiscipline(string groupNumber, deliveryDisciplines _deliveryDisciplines) {

	// Файловый поток
	ofstream file("GroupDiscipline-" + groupNumber + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	int counter = 1;

	for_each(_deliveryDisciplines._deliveryDisciplines[groupNumber].begin(), _deliveryDisciplines._deliveryDisciplines[groupNumber].end(),
		[&counter, &file](deliveryDisciplines::discipline item) {
			// Выводим в консоль
			cout << left << " #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			file << left << " #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			++counter;
		}	
	);

	return true;
}

// Метод вывода дисциплин всего факультета
bool reports::getFacultyDescipline(deliveryDisciplines _deliveryDisciplines) {
	
	// Файловый поток
	ofstream file("GroupDiscipline.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	_deliveryDisciplines.element = _deliveryDisciplines._deliveryDisciplines.begin();

	for (int i = 0; _deliveryDisciplines.element != _deliveryDisciplines._deliveryDisciplines.end(); _deliveryDisciplines.element++) {
		int counter = 1;

		cout << " Дисциплины \"" << _deliveryDisciplines.element->first << "\" группы для сдачи"<< endl;
		file << " Дисциплины \"" << _deliveryDisciplines.element->first << "\" группы для сдачи"<< endl;

		for_each(_deliveryDisciplines.element->second.begin(), _deliveryDisciplines.element->second.end(),
			[&counter, &file](deliveryDisciplines::discipline item) {
				// Выводим в консоль
				cout << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
				file << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
				++counter;
			}
		);

		cout << endl;
		file << endl;
	}

	return true;
}

// Метод вывода оценок студента
bool reports::getStudentGrade(ratingList _rating, studentList _student) {

	// Выводим список всех студентов
	_student.output();

	int studentID;

	cout << " Введите ID студента: ";
	cin >> studentID;

	// Если нет такого студента
	if (studentID < 0 || (unsigned) studentID > _student._studentList.size()) {
		cout << " Студента с ID-" << studentID << " не существует" << endl;
		return false;
	}

	// Получаем имя студента 
	string studentName = _rating.getStudentNameByID(studentID, _student);

	// Файловый поток
	ofstream file(studentName + " Grade" + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}



	// Получаем группу студента
	string studentGroup = _student._studentList[studentID - 1]["group"];

	cout << " Оценки студента \"" << studentName << "\" \"" << studentGroup << "\" группы" << endl;
	file << " Оценки студента \"" << studentName << "\" \"" << studentGroup << "\" группы" << endl;

	int counter = 1;


	// Итератор на список студентов из группы
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[studentGroup].begin();

	// Вывод списка оценок для студента
	for (; element != _rating._ratingList[studentGroup].end(); ++element) {
		//Находим студента
		if (element->first == studentName) {
			for (ratingList::rating item : element->second) {
				cout << " \t #" << counter << " " << item.discipline << " - " << item.grade << endl;
				file << " \t #" << counter << " " << item.discipline << " - " << item.grade << endl;
				++counter;
			}
			break;
		}
	}

	return true;
}

// Метод вывода оценок студентов выбранной группы
bool reports::getGroupGrade(ratingList _rating, groupList _group) {

	string groupNumber;

	cout << " Введите номер группы: ";
	cin >> groupNumber;

	if (!_group.checkGroup(groupNumber)) {
		cout << " Группы \"" << groupNumber << "\" не существует" << endl;
		return false;
	}


	// Файловый поток
	ofstream file(groupNumber + "group grade" + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}



	cout << " Оценки студентов \"" << groupNumber <<  "\" группы" << endl;
	file << " Оценки студентов \"" << groupNumber <<  "\" группы" << endl;

	// Итератор на список студентов из группы
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[groupNumber].begin();

	cout << "\t " << setw(38) << "  ";
	file << "\t " << setw(38) << "  ";

	// Вывод предметов
	for (ratingList::rating item : element->second) {
		file << left << setw(25) << item.discipline;
		cout << left << setw(25) << item.discipline;
	}

	cout << endl;
	file << endl;

	// Вывод списка оценок для студента
	for (int counter = 1; element != _rating._ratingList[groupNumber].end(); ++element, ++counter) {
		cout << "\t #" << counter << " " << setw(35) << element->first; // Выводим имя
		file << "\t #" << counter << " " << setw(35) << element->first; // Выводим имя
		// Выводим оценки
		for (ratingList::rating item : element->second) {
			cout << left << setw(25) << item.grade;
			file << left << setw(25) << item.grade;
		}

		cout << endl;
		file << endl;
	}

	return true;
}

// Метод вывода студентов не сдавших сессию
bool reports::getStudentNotPassSession(ratingList _rating) {



	// Файловый поток
	ofstream file("studentNotPassSession.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}


	// Итератор списка 
	map<string, map<string, vector<ratingList::rating>>> :: iterator it = _rating._ratingList.begin();

	// Проходимся по списку оценок каждого студента и выводим тех кто не сдал
	for (int counter = 1; it != _rating._ratingList.end(); ++it) {

		map<string, vector<ratingList::rating>> ::iterator it2 = it->second.begin();

		for (; it2 != it->second.end(); ++it2, ++counter) {
			vector<ratingList::rating> ::iterator it3 = it2->second.begin();

			for (;it3 != it2->second.end(); ++it3) {
				if (it3->grade == "Не указано" || it3->grade == "незачет" || it3->grade == "2") {
					cout << " #" << counter << " " << it2->first << " " << it->first << endl;
					file << " #" << counter << " " << it2->first << " " << it->first << endl;
					break;
				}
			}
		}

	}

	return true;
}

// Метод вывода среднего балла по группе
double reports::getGroupAverage(ratingList _rating, string groupNumber) {


	// Файловый поток
	ofstream file("GroupAverage-" + groupNumber + ".txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}

	// Итератор на список студентов из группы
	map <string, vector<ratingList::rating>> ::iterator element = _rating._ratingList[groupNumber].begin();

	double average = 0;
	int counter = 0;

	// Вывод списка оценок для студента
	for (; element != _rating._ratingList[groupNumber].end(); ++element, ++counter) {
		// Выводим оценки
		for (ratingList::rating item : element->second) {
			if (item.grade == "2" || item.grade == "3" || item.grade == "4" || item.grade == "5") {
				average += stoi(item.grade);
			}
		}
	}


	file << " Средняя оценка \"" << groupNumber << "\" группы: ";

	if (average == 0) {
		return 0;
		file << 0;
	}

	file << average / (double)counter;

	return average / (double) counter;
}

// Метод вывода стреднего балла по факультету
double reports::getFacultyAverage(ratingList _rating, studentList _student) {
	// Файловый поток
	ofstream file("facultyAverage.txt");

	// Если файл не удалось открыть
	if (!file) {
		cerr << " Ошибка! Не удалось открыть файл для записи!" << endl;
		return false;
	}


	// Итератор списка 
	map<string, map<string, vector<ratingList::rating>>> ::iterator it = _rating._ratingList.begin();

	double average = 0;
	int counter = 0;

	// Проходимся по списку оценок каждого студента и выводим тех кто не сдал
	for (; it != _rating._ratingList.end(); ++it) {

		map<string, vector<ratingList::rating>> ::iterator it2 = it->second.begin();

		for (; it2 != it->second.end(); ++it2, ++counter) {
			vector<ratingList::rating> ::iterator it3 = it2->second.begin();

			for (; it3 != it2->second.end(); ++it3) {
				if (it3->grade == "2" || it3->grade == "3" || it3->grade == "4" || it3->grade == "5") {
					average += stoi(it3->grade);
				}
			}
		}

	}

	file << " Средняя оценка факультета: ";

	if (average == 0) {
		return 0;
		file << 0;
	}

	file << average / (double)counter;

	return average / (double)counter;
}