#include "library.h"

class groupList;
class ratingList;
class reports;

class studentList {
	public: // Публичная область класса

		// Метод считывание списка студентов с файла
		bool read(groupList _group, string filename = "student");

		// Метод для записи списка студентов в файл
		bool write(string filename = "newStudent");

		// Метод добавления студента в список
		bool create(groupList _group);

		// Метод изменения информации о студенте
		bool update(int id, groupList _group);

		// Метод удаление информации о студенте
		bool remove(int id);

		// Метод вывода студентов в консоль
		bool output();

	private: // Закрытая область класса

		// Перменные для хранения ФИО
		string name, surename, middlename;
		// Храним пол студента
		string sex;
		// Номер группы 
		string group;

		// Храним последовательность записи в map
		vector<string> writeQueue = {
			"surename",
			"name",
			"middlename",
			"group",
			"sex"
		};


		// Метод для создание нового студента
		void append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);


		// Метод обнуляет перменные класса
		void resetVariables();

		// Метод собирает строку 
		string assemblyString(map<string, string> element);

		// Метод для проверки пуст ли список студентов
		bool empty();

		// Метод для проверки существует ли группа
		bool checkGroup(string groupNumber, groupList _group);

		// Вектор хранит информацию о студентах
		vector<map<string, string>> _studentList; // Классом

		// Объявялем дружественный класс
		friend ratingList;
		friend groupList;
		friend reports;
};

