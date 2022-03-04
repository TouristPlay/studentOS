#include "library.h"
#include "studentList.h"

class groupList {
	public: // Публичная область класса

		// Метод считывание списка групп
		bool read(string filename = "group");

		// Метод для записи списка студентов в файл
		bool write(string filename = "newGroup");

		// Метод добавления группы в список
		bool create();

		// Метод изменения информации о группе
		bool update(int id);

		// Метод удаление информации о группе
		bool remove(int id, studentList _student);

		// Метод вывода списка групп в консоль
		bool output();

	private: // Закрытая область класса

		// Курс круппы
		string course;
		// Номер группы
		string group;
		// Имя специальности
		string speciality;


		// Храним последовательность записи в map
		vector<string> writeQueue = {
			"group",
			"course",
			"speciality",
		};

		// Метод для проверки пуст ли список групп
		bool empty();

		// Метод для создание новой группы
		void append(string newGroup, string newCourse, string newSpeciality);

		// Метод обнуляет перменные класса
		void resetVariables();

		// Метод собирает строку 
		string assemblyString(map<string, string> element);

		// Метод проверяет, если студент в группе
		bool checkStudent(string group, studentList _student);

		// Список всей группы
		vector <map<string, string>> _groupList;

		// Объявляем дружественный класс
		friend studentList;
};

