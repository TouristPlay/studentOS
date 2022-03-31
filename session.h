#include "library.h"

#include "discipline.h"

class studentList;

class session {


	public:
		// Конструктор
		session();

		session(string newType, string newData, discipline newSubject);

		// Метод для получения типа сдачи сессии
		string getType();

		// Метод для получения даты сдачи сессии
		string getDate();

		// Метод для получении имени дисциплины
		string getDisciplineName();

		// Метод для получение ID дисциплины 
		unsigned getDisciplineID();

		// Метод для изменения даты сессии
		void setDate(string newDate);

		// Мето для изменения типа сессии
		void setType(string newType);
		

	private:	

		string type; // Тип сдачи экзамен/зачет/курсовая
		string date; // Дата сдачи экзамена
		discipline subject; // Предмет для сдачи


		friend studentList;
};
