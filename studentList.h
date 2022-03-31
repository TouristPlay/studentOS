#include "library.h"
#include "student.h"

class disciplineList;
class groupList;

class studentList {
	public:
		// Метод считывание списка студентов с файла
		bool read(groupList &_group, string filename = "student");

		// Метод для записи списка студентов в файл
		bool write(string filename = "newStudent");

		// Метод добавления студента в список
		bool create(groupList &_group);

		// Метод изменения информации о студенте
		bool update(unsigned id);

		// Метод удаление информации о студенте
		bool remove(unsigned id);

		// Метод вывода студентов в консоль
		bool output();

		// Метод для добавление оценки студенту
		bool createRating(disciplineList &_discipline, groupList &_group, unsigned groupID);

		// Метод для получение оценок студента
		bool getStudentGrade();

		// Метод для получения оценок факультета
		bool getGroupGrade(unsigned groupID, groupList& _group);

		// Метод для получения списка студентов не сдавших сессию
		bool getStudentNotPassSession();

		// Метод для получения среднего балла по группе 
		bool getGroupAverage(unsigned groupID, groupList& _group);

		// Метод для получения среднего балла по факультету
		bool getFacultyAverage();

	private:

		// Перменные для хранения ФИО
		string name, surename, middlename;
		// Храним пол студента
		string sex;
		// Номер группы 
		string groupNumber;

		// Приватный метод для проверки пуст ли список студентов
		bool empty();

		// Метод обнуляет перменные класса
		void resetVariables();

		// Метод проверяет есть ли такой ID
		bool checkID(unsigned ID);

		// Метод для проверки существует ли группа
		bool checkGroup(string groupNumber, groupList _group);

		// Метод для получения студентов опредленной группы
		bool getGroupStudent(string groupName);

		// Метод для ввода данных
		void input();

		// Метод получает студента по ID
		student &getStudentByID(unsigned ID);

		// Метод для создание нового студента
		void append(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);

		// Вектор хранит список студентов
		vector<student> _studentList;

		friend groupList;
};

