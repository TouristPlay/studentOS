#include "library.h"

#include "rating.h"

class studentList;
class groupList;

class student {

	public:

		// Конструктор класса 
		student();

		student(string newName, string newSurename, string newMiddlename, string newSex, string newGroup);

		// Метод для получения имени студента
		string getName();

		// Метод для получения пола студента
		string getSex();

		// Метод для получения группы
		string getGroup();

		// Метод для получения ID
		unsigned getID();

		// Метод для изменнеия имени студента
		void changeName(string newName, string newSurename, string newMiddlename);

		// Метод для изменнеия пола
		void changeSex(string newSex);

		// Метод для изменения грурры
		void changeGroup(string newGroup);

	private:

		// Перменные для хранения ФИО
		string name, surename, middlename;
		// Храним пол студента
		string sex;
		// Номер группы 
		string group;
		// ID
		unsigned ID;
		// Генератор ID
		static unsigned idGenerator;

		// Список оценок за сессию
		vector<rating> _rating;

		friend studentList;
		friend groupList;
};

