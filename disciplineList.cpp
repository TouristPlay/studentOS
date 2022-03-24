#include "disciplineList.h"


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
		// Добавляем в список 
		this->_disciplineList.push_back(this->disciplineName);
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

		// Записываем в файл
		for_each(this->_disciplineList.begin(), this->_disciplineList.end(),
			[&file](string element) {
				file << element << endl;
			}
		);

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


	//--Проверка есть ли студент в группе--///

	// Добавляем группы в список
	this->_disciplineList.push_back(this->disciplineName);

	return true;
}

// Публиный метод изменения информации о группе
bool disciplineList::update(int id) {
	if (empty() || id > (int)this->_disciplineList.size() || id < 0) {
		return false;
	}
	// Выводим найденную дисциплину
	cout << " Дисциплина " << " \"#" << id << " " << _disciplineList[id - 1] << "\" найдена" << endl;

	// Создаем новую группу
	this->create();

	// Меняем местами группы
	swap(this->_disciplineList[id - 1], this->_disciplineList[this->_disciplineList.size() - 1]);

	// Удаляем группу в которого нужно внести поправки
	this->_disciplineList.erase(_disciplineList.end() - 1);

	return true;
}

// Публиный метод удаление информации о группе
bool disciplineList::remove(int id) {
	if (empty() || id > (int)this->_disciplineList.size() || id < 0) {
		return false;
	}
	// Удаляем группу из списка
	this->_disciplineList.erase(_disciplineList.begin() + id - 1);
	return true;
}

// Публиный метод вывода списка групп в консоль
bool disciplineList::output() {

	if (empty()) {
		return false;
	}

	// Счетчик
	int counter = 1;

	// Выводим список дисциплин
	for_each(this->_disciplineList.begin(), this->_disciplineList.end(),
		[&counter](string element) {
			// Выводим строку в консоль
			cout << "\t #" << counter << " " << element << endl;
			// Увеличиваем счетчик
			++counter;
		}
	);
	return true;
}


// Приватный метод для проверки пуст ли список дисциплин
bool disciplineList::empty() {
	return this->_disciplineList.empty();
}
