#include "library.h"

#include "studentList.h"
#include "disciplineList.h"
#include "groupList.h"


class menu {
public:

	// Функция для вывода основного меню
	void main() {

		// Выводим шапку
		header();

		cout << " Главное меню" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Группы" << endl;
		cout << "\t 2. Студенты" << endl;
		cout << "\t 3. Дисциплины" << endl;
		cout << "\t 4. Сессия" << endl;
		cout << "\t 5. Оценки" << endl;
		cout << "\t 6. Отчеты" << endl;

		cout << endl;



	}


	// Функция вывода меню пункта групп
	void group() {

		// Выводим шапку
		header();

		cout << " Главное меню --> Группы" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Считать с файла" << endl;
		cout << "\t 2. Запись в файл" << endl;
		cout << "\t 3. Добавить группу" << endl;
		cout << "\t 4. Обновить группу" << endl;
		cout << "\t 5. Удалить группу" << endl;
		cout << "\t 6. Вывести список" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}


	// Функция вывода меню пункта студенты
	void student() {

		// Выводим шапку
		header();

		cout << " Главное меню --> Студенты" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Считать с файла" << endl;
		cout << "\t 2. Запись в файл" << endl;
		cout << "\t 3. Добавить студента" << endl;
		cout << "\t 4. Обновить студента" << endl;
		cout << "\t 5. Удалить студента" << endl;
		cout << "\t 6. Вывести список" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}

	// Функция вывода меню пункта дисциплины
	void discipline() {

		// Выводим шапку
		header();

		cout << " Главное меню --> Дисциплины" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Считать с файла" << endl;
		cout << "\t 2. Запись в файл" << endl;
		cout << "\t 3. Добавить дисциплины" << endl;
		cout << "\t 4. Обновить дисциплину" << endl;
		cout << "\t 5. Удалить дисциплину" << endl;
		cout << "\t 6. Вывести список" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}

	// Функция вывода меню пункта сессия
	void delivery() {

		// Выводим шапку
		header();

		cout << " Главное меню --> Сессия" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Добавить дисциплины" << endl;
		cout << "\t 2. Обновить дисциплину" << endl;
		cout << "\t 3. Удалить дисциплину" << endl;
		cout << "\t 4. Вывести список" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}


	// Функция вывода меню пункта оценки
	void rating() {

		// Выводим шапку
		header();

		cout << " Главное меню --> Оценки" << endl;
		cout << "\n Выберите пункт меню: " << endl;

		cout << "\t 1. Добавить оценки" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}



	// Функция вывода меню пункта оценки
	void report() {

		// Выводим шапку
		header();

		cout << "\t 1. Дисциплины группы" << endl;
		cout << "\t 2. Дисциплины факультета " << endl;
		cout << "\t 3. Оценки студента" << endl;
		cout << "\t 4. Оценки группы" << endl;
		cout << "\t 5. Список заваливших сессию" << endl;
		cout << "\t 6. Средняя оценка по группе" << endl;
		cout << "\t 7. Средняя оценка по факультету" << endl;
		cout << "\t 0. Назад" << endl;

		cout << endl;
	}


private:

	// Функция шапки OS
	void header() {

		// Шапка меню
		cout << "**********************************************************************" << endl;
		cout << endl;

		cout << setw(40) << "_StudentOS_" << endl;
		cout << setw(48) << "product by TouristTechology" << endl;

		cout << endl;
		cout << "**********************************************************************" << endl;

		cout << endl;
	}
};

// Функция для продолжения вывода
void proceed();

int main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Ставим заголовок консоли
	SetConsoleTitle(L"StudentOS by TouristTechology");

	// Создаем объекты
	groupList group;
	studentList student;
	disciplineList discipline;
	menu _menu;

	// Вспомогательные перменные для меню
	int menuItem = 0;
	int id = 0;
	bool flag;
	string filename;
	string change;
	string groupNumber;

	// Интерфейс OS
	do {
		system("cls");
		_menu.main();

		cout << " Введите пункт меню: ";
		cin >> menuItem;

		switch (menuItem) {
		case 1: // Выводим меню групп

			do {
				system("cls");
				_menu.group();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Считываение с файла
					cout << " Файл считывание по умолчанию group. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = group.read(filename);
					}
					else {
						flag = group.read();
					}


					if (flag) {
						cout << " Файл успешно считан" << endl;
					}


					// Продолжения работы
					proceed();

					break;
				case 2:	// Запись в  файл
					cout << " Файл записи по умолчанию newGroup. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = group.write(filename);
					}
					else {
						flag = group.write();
					}

					if (flag) {
						cout << " Список записан в файл" << endl;
					}
					else {
						cout << " Список пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 3: // Добавить группу

					if (group.create()) {
						cout << " Группа успешно добавлена в список" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 4: // Обновить группу

					group.output();
					cout << endl;

					cout << " Введите ID группы: ";
					cin >> id;

					if (group.update(id) == false) {
						cout << " Список пуст или группы не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 5: // Удалить группу

					group.output();
					cout << endl;

					cout << " Введите ID группы: ";
					cin >> id;

					if (group.remove(id, student) == false) {
						cout << " Список пуст или группы не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 6: // Вывести список


					if (group.output() == false) {
						cout << " Список пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
					// Назад
				case 0:

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}


			} while (menuItem != 0);


			break;
		case 2:// Выводим меню студентов

			do {
				system("cls");
				_menu.student();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Считываение с файла
					cout << " Файл считывание по умолчанию student. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = student.read(group, filename);
					}
					else {
						flag = student.read(group);
					}


					if (flag) {
						cout << " Файл успешно считан" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 2:	// Запись в  файл
					cout << " Файл записи по умолчанию newStudent. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = student.write(filename);
					}
					else {
						flag = student.write();
					}

					if (flag) {
						cout << " Список записан в файл" << endl;
					}
					else {
						cout << " Список пуст" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 3: // Добавить студента

					if (student.create(group)) {
						cout << " Студент успешно добавлена в список" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 4: // Обновить студента

					if (!student.output()) {
						cout << " Список пуст!" << endl;
						// Продолжения работы
						proceed();
						break;
					}
					cout << endl;

					cout << " Введите ID студента: ";
					cin >> id;

					if (!student.update(id)) {
						cout << " Студента не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 5: // Удалить студента

					if (!student.output()) {
						cout << " Список пуст!" << endl;
						// Продолжения работы
						proceed();
						break;
					}
					cout << endl;

					cout << " Введите ID студента: ";
					cin >> id;

					if (!student.remove(id)) {
						cout << " Студента не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 6: // Вывести список


					if (!student.output()) {
						cout << " Список пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
					// Назад
				case 0:

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}
			} while (menuItem != 0);


			break;
		case 3: // Выводим меню дисциплин

			do {
				system("cls");
				_menu.discipline();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Считываение с файла
					cout << " Файл считывание по умолчанию discipline. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = discipline.read(filename);
					}
					else {
						flag = discipline.read();
					}


					if (flag) {
						cout << " Файл успешно считан" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 2:	// Запись в  файл
					cout << " Файл записи по умолчанию newStudent. Изменить? [Y/N]: ";
					cin >> change;

					if (change == "Y") {
						cout << " Введите имя файла: ";
						cin >> filename;
						flag = discipline.write(filename);
					}
					else {
						flag = discipline.write();
					}

					if (flag) {
						cout << " Список записан в файл" << endl;
					}
					else {
						cout << " Список пуст" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 3: // Добавить дисциплину

					if (discipline.create()) {
						cout << " Дисциплина успешно добавлена в список" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 4: // Обновить дисциплину

					if (!discipline.output()) {
						cout << " Список пуст!" << endl;
						// Продолжения работы
						proceed();
						break;
					}
					cout << endl;

					cout << " Введите ID дисциплины: ";
					cin >> id;

					if (discipline.update(id) == false) {
						cout << " Список пуст или дисциплины не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 5: // Удалить дисциплину

					if (!discipline.output()) {
						cout << " Список пуст!" << endl;
						// Продолжения работы
						proceed();
						break;
					}
					cout << endl;

					cout << " Введите ID дисциплины: ";
					cin >> id;

					if (discipline.remove(id) == false) {
						cout << " Список пуст или дисциплины не существует!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 6: // Вывести список


					if (discipline.output() == false) {
						cout << " Список пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
					// Назад
				case 0:

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}
			} while (menuItem != 0);

			break;
		case 4:// Выводим меню дисциплин для сдачи

			do {
				system("cls");
				_menu.delivery();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Добавить дисциплину
					if (!group.output()) {
						cout << " Список пуст" << endl;
						// Продолжения работы
						proceed();
						break;
					}

					cout << " Введите ID группы: ";
					cin >> id;

					group.createDiscipline(discipline, student, id);

					// Продолжения работы
					proceed();

					break;
				case 2: // Обновить дисциплину
					
					if (!group.output()) {
						cout << " Список пуст" << endl;
						// Продолжения работы
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					group.updateDiscipline(id);

					// Продолжения работы
					proceed();

					break;
				case 3: // Удалить дисциплину
					
					if (!group.output()) {
						cout << " Список пуст" << endl;
						// Продолжения работы
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					group.removeDiscipline(id);

					// Продолжения работы
					proceed();

					break;
				case 4: // Вывести список

					if (!group.output()) {
						cout << " Список пуст" << endl;
						// Продолжения работы
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					group.getGroupDiscipline(id);

					// Продолжения работы
					proceed();

					break;

				case 0:	// Назад

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}
			} while (menuItem != 0);

			break;
		case 5: // Выводим меню оценок

			do {
				system("cls");
				_menu.rating();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Добавить дисциплину

					if (!group.output()) {
						cout << " Список пуст" << endl;
						// Продолжения работы
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					student.createRating(discipline, group, id);

					// Продолжения работы
					proceed();

					break;

				case 0:	// Назад

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}


			} while (menuItem != 0);

			break;
		case 6:// Выводим меню отчетов
			do {
				system("cls");
				_menu.report();


				cout << " Введите пункт меню: ";
				cin >> menuItem;

				switch (menuItem) {
				case 1: // Дисциплины группы


					if (!group.output()) {
						cout << " Список пуст!" << endl;
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					if (!group.getGroupDiscipline(id)) {
						cout << " Список групп или дисциплин пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 2: // Дисциплины факультета

					if (!group.getFacultyDescipline()) {
						cout << " Список дисциплин или групп пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 3: // Оценки студента

					student.getStudentGrade();

					// Продолжения работы
					proceed();

					break;
				case 4: // Оценки группы

					if (!group.output()) {
						cout << " Список пуст!" << endl;
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;

					student.getGroupGrade(id, group);

					// Продолжения работы
					proceed();

					break;
				case 5: // Список не сдавших сессию

					if (!student.getStudentNotPassSession()) {
						cout << " Список оценок или студентов пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 6: // Средняя оценка по группе

					if (!group.output()) {
						cout << " Список пуст!" << endl;
						proceed();
						break;
					}

					cout << " Введие ID группы: ";
					cin >> id;


					if (!student.getGroupAverage(id, group)) {
						cout << " Список оценок пуст!" << endl;
					}

					// Продолжения работы
					proceed();

					break;
				case 7: // Средняя оценка по факультету


					if (!student.getFacultyAverage()) {
						cout << " Список оценок или студентов пуст!" << endl;
					}


					// Продолжения работы
					proceed();

					break;
				case 0:	// Назад

					break;

				default:
					cout << " Такого пункта меню не существует!" << endl;
					break;
				}


			} while (menuItem != 0);

			break;
		default:
			cout << " Такого пункта меню не существует" << endl;
			break;
		}

	} while (true);



	cout << endl;
	system("pause");
	return 0;
}

// Функция для продолжения вывода
void proceed() {
	cout << " Для продолжения нажмите любую клавишу...";
	char a = getchar();
	a = getchar();
}