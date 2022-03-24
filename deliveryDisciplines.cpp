#include "deliveryDisciplines.h"
#include "disciplineList.h"


// Публичный метод добавление дисциплины для сдачи
bool deliveryDisciplines::create(disciplineList _discipline, string groupNumber) {

	string status = "Y";

	_discipline.output();

	do {

		cout << " Группа \"" << groupNumber << "\"" << endl;

		// Вводим дисциплину
		cout << " Введите ID дисциплины: ";
		cin >> this->disciplineId;

		// Получение имени дисциплины
		string disciplineName = _discipline._disciplineList[this->disciplineId - 1];

		// Если выбрал не тот ID
		if ((unsigned)this->disciplineId > _discipline._disciplineList.size() || this->disciplineId < 1) {
			cout << " Такой дисциплины не существует!" << endl;
			return false;
		}
		// Если выбрали дисциплину которая есть уже в списке
		if (repeatInclude(disciplineName, groupNumber)) {
			cout << " Дисциплина \"" << disciplineName << "\" уще существует!" << endl;
			return false;
		}

		// Вводим тип сдачи
		cout << " Введите тип сдачи: ";
		cin.ignore();
		getline(cin, this->deliveryType);
		// Вводим дату сдачи
		cout << " Введите дату сдачи: ";
		getline(cin, this->deliveryDate);


		// Вызываем метод добавления
		this->append(groupNumber, disciplineName, this->deliveryType, this->deliveryDate);

		cout << " Вы хотите продолжить ввод? [Y/N]: ";
		cin >> status;

		// Если ввод неверный завершаем цикл
		if (!(status != "N" || status != "Y")) break;

	} while (status != "N");

	return true;
};

// Публичный метод изменения информации
bool deliveryDisciplines::update(string groupNumber) {

	// Если списко пуст
	if (this->empty()) {
		cout << " Список пуст!" << endl;
		return false;
	}

	// Находим нужную ячейку в списке
	this->element = this->_deliveryDisciplines.find(groupNumber);

	// Если группа не найден
	if (this->element == this->_deliveryDisciplines.end()) {
		cout << " Группа \"" << groupNumber << "\" не найдена!" << endl;
		return false;
	}

	// Выводим список дисциплин для группы
	this->output(groupNumber);

	cout << " Введите ID записи для изменения : ";
	cin >> this->disciplineId;

	// Если выбрал не тот ID
	if ((unsigned)this->disciplineId > this->element->second.size() || this->disciplineId < 1) {
		cout << " Такой записи не существует!" << endl;
		return false;
	}

	// Обновляем информацию о сдаваемой дисциплине
	cout << " Введите тип сдачи: ";
	cin.ignore();
	getline(cin, element->second[disciplineId - 1].type);
	// Вводим дату сдачи
	cout << " Введите дату сдачи: ";
	getline(cin, element->second[disciplineId - 1].date);

	return true;
};

// Публичный метод удаления информации о дисциплине
bool deliveryDisciplines::remove(string groupNumber) {

	// Если списко пуст
	if (this->empty()) {
		cout << " Список пуст!" << endl;
		return false;
	}


	// Находим нужную ячейку в списке
	this->element = this->_deliveryDisciplines.find(groupNumber);

	// Если группа не найден
	if (this->element == this->_deliveryDisciplines.end()) {
		cout << " Группа \"" << groupNumber << "\" не найдена!" << endl;
		return false;
	}

	// Выводим список дисциплин для группы
	this->output(groupNumber);

	cout << " Введите ID записи для удаления : ";
	cin >> this->disciplineId;

	// Если выбрал не тот ID
	if ((unsigned)this->disciplineId > this->element->second.size() || this->disciplineId < 1) {
		cout << " Такой записи не существует!" << endl;
		return false;
	}

	// Удаляем запись
	element->second.erase(element->second.begin() + disciplineId - 1);

	return true;
};

// Публичный метод вывода дисциплин для группы
bool deliveryDisciplines::output(string groupNumber) {

	// Если списко пуст
	if (this->empty()) {
		return false;
	}

	// Находим нужную ячейку в списке
	this->element = this->_deliveryDisciplines.find(groupNumber);

	int counter = 1;
	// Выводим дисциплины
	for_each(this->element->second.begin(), this->element->second.end(), 
		[&counter](discipline item) {
			cout << left << "\t #" << counter << " | " << setw(25) << item.name << " | " << setw(15) << item.type << " | " << item.date << endl;
			++counter;
		}
	);

	return true;
};

// Приватный метод добавления дисциплины в список сдачи
bool deliveryDisciplines::append(string newGroup, string newDisciplineName, string newDeliveryType, string newDeliveryDate) {
	

	// Заполняем структуру
	disciplineInfo.name = newDisciplineName; // Имя дисциплины
	disciplineInfo.type = newDeliveryType; // Тип сдачи
	disciplineInfo.date = newDeliveryDate; // Дата сдачи


	// Добавляем дисциплину для сдачи в список
	this->_deliveryDisciplines[newGroup].push_back(disciplineInfo);

	// Обнуляем все перменные
	this->resetVariabless();

	return true;
	
};

// Приватный метод для обнуления переменных
void deliveryDisciplines::resetVariabless() {

	this->group = "";
	int disciplineId = 0;
	string deliveryType = "";
	string deliveryDate = "";
	this->disciplineInfo = { };
}

// Приватный метод для проверки пустой ли список
bool deliveryDisciplines::empty() {
	return this->_deliveryDisciplines.empty();
}

// Приватный метод проверяет повторное добавление дисциплины
bool deliveryDisciplines::repeatInclude(string subjectName, string groupNumber) {

	// Находим нужную ячейку в списке
	this->element = this->_deliveryDisciplines.find(groupNumber);

	bool flag = false;

	if (this->element == this->_deliveryDisciplines.end()) {
		return flag;
	}

	//Проходимся по вектору
	for_each(this->element->second.begin(), this->element->second.end(),
		[&flag, subjectName](discipline item) {
			if (item.name == subjectName) {
				flag = true;
			}
		}
	);

	return flag;
}