#include "library.h"

class disciplineList;
class ratingList;
class reports;

class deliveryDisciplines {
	public:

		// Публичный метод добавление дисциплины для сдачи
		bool create(disciplineList _discipline, string groupNumber);

		// Публичный метод изменения информации
		bool update(string groupNumber);

		// Публичный метод удаления информации о дисциплине
		bool remove(string groupNumber);

		// Публичный метод вывода дисциплин для группы
		void output(string groupNumber);
	private:

		string group; // Группа
		int disciplineId = 0; // Дисциплина
		string deliveryType; // Тип сдачи экзамен/зачет/курсовая
		string deliveryDate; // Дата сдачи экзамена

		// Хранит данные об одной дисциплине
		struct discipline
		{
			string name; // Имя дисциплины
			string type; // Тип сдачи
			string date; // Дата сдачи
		};

		discipline disciplineInfo;

		// Метод добавления дисциплины в список сдачи
		bool append(string newGroup, string newDisciplineId, string newDeliveryType, string newDeliveryDate);

		// Метод для обнуления переменных
		void resetVariabless();

		// Метод проверяет повторное добавление дисциплины
		bool repeatInclude(string subjectName, string groupNumber);

		// Метод для проверки пустой ли список
		bool empty();

		// Содержит список сдаваемых дисциплин для группы
		map <string, vector<discipline>> _deliveryDisciplines;

		// Итератор на список 
		map <string, vector<discipline>> ::iterator element;
		

		friend ratingList;
		friend reports;
};
