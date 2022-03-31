#include "library.h"

#include "discipline.h"
class studentList;
class groupList;

class rating {


	public:

		// Конструктор
		rating(discipline subject, string grade);

		// Метод для получение имени предмета
		string getName();

		// Метод для получения оценки предмета
		string getGrade();

		// Метод для изменение оценки
		void setGrade(string grade);

	private:

		discipline subject; // Дисциплина
		string grade; // Оценка

		friend studentList;
		friend groupList;
};

