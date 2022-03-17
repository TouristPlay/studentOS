#include "library.h"

class deliveryDisciplines;

// Класс дисциплин
class disciplineList {
	public: // Публичная область класса

		// Публиный метод чтения списка дисциплин из файла
		bool read(string filename = "discipline");

		// Публиный метод записи списка дисциплин в файл
		bool write(string filename = "newDiscipline");

		// Публиный метод создает новую дисциплину
		bool create();

		// Публиный методизменения информации о группе
		bool update(int id);

		// Публиный метод удаление информации о группе
		bool remove(int id);

		// Публиный метод вывода списка групп в консоль
		bool output();


	private: // Закрытая область класса

		string disciplineName;

		// Приватный метод для проверки пуст ли список дисциплин
		bool empty();

		// Список дисциплин
		vector<string> _disciplineList;

		// Объявляем дружественный класс
		friend deliveryDisciplines;
};

