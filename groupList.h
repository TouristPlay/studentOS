#include "library.h"
#include "group.h"

class studentList;

class groupList {

	public:

		// Метод считывание списка групп
		bool read(string filename = "group");

		// Метод для записи списка студентов в файл
		bool write(string filename = "newGroup");

		// Метод добавления группы в список
		bool create();

		// Метод изменения информации о группе
		bool update(unsigned id);

		// Метод удаление информации о группе
		bool remove(unsigned id, studentList &_student);

		// Метод вывода списка групп в консоль
		bool output();

		// Метод добавления дисциплины для сдачи
		bool createDiscipline(disciplineList& _discipline, studentList &_student, unsigned ID);

		// Метод для обновления предмета для сдачи
		bool updateDiscipline(unsigned ID);

		// Метод для удаления предмета для сдачи
		bool removeDiscipline(unsigned ID);

		// Метод для получения списка дисциплин
		bool getGroupDiscipline(unsigned ID);

		// Метод вывода дисциплин всего факультета
		bool getFacultyDescipline();

	private:

		// Курс круппы
		string course;
		// Номер группы
		string groupNumber;
		// Имя специальности
		string speciality;

		// Метод для проверки пуст ли список групп
		bool empty();

		// Метод для создание новой группы
		void append(string newGroup, string newCourse, string newSpeciality);

		// Метод обнуляет перменные класса
		void resetVariables();

		// Метод для проверки существует ли группа
		bool checkGroup(string groupNumber);

		// Метод проверяет, есть ли студент в группе
		bool checkStudent(string group, studentList &_student);

		// Метод получается группу по ID
		group &getGroupByID(unsigned ID);

		// Метод проверяет есть ли такой ID
		bool checkID(unsigned ID);

		// Метод для считывания строки
		void input();

		// Список всех групп
		vector <group> _groupList; 

		friend studentList;
};

