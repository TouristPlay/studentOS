#include "library.h"

class discipline;
class studentList;
class groupList;

class disciplineList {

	public:
		// Публиный метод чтения списка дисциплин из файла
		bool read(string filename = "discipline");

		// Публиный метод записи списка дисциплин в файл
		bool write(string filename = "newDiscipline");

		// Публиный метод создает новую дисциплину
		bool create();

		// Публиный методизменения информации о группе
		bool update(unsigned id);

		// Публиный метод удаление информации о группе
		bool remove(unsigned id);

		// Публиный метод вывода списка групп в консоль
		bool output();

	private:

		string disciplineName;

		// Приватный метод для проверки пуст ли список дисциплин
		bool empty();

		// Метод получение дисциплина по ID
		discipline &getDisciplineByID(unsigned ID);

		// Метод проверки, если ли уже такая дисциплина
		bool checkDiscipline(string disciplineName);

		// Метод для проверки существует ли такой ID
		bool checkID(unsigned ID);

		// Список дисциплин
		vector<discipline> _disciplineList;

		friend groupList;
		friend studentList;
};

