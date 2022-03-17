#include "library.h"

class deliveryDisciplines;
class ratingList;
class studentList;
class groupList;

class reports {

	public:

		// Метод вывода дисциплин для сдачи конкретной группы
		bool getGroupDiscipline(string groupNumber, deliveryDisciplines _deliveryDisciplines);

		// Метод вывода дисциплин всего факультета
		bool getFacultyDescipline(deliveryDisciplines _deliveryDisciplines);

		// Метод вывода оценок студента
		bool getStudentGrade(ratingList _rating, studentList _student);

		// Метод вывода оценок студента выбранной группы
		bool getGroupGrade(ratingList _rating, groupList _group);

		// Метод вывода студентов не сдавших сессию
		bool getStudentNotPassSession(ratingList _rating);

		// Метод вывода среднего балла по группе
		double getGroupAverage(ratingList _rating, string groupNumber);

		// Метод вывода стреднего балла по факультету
		double getFacultyAverage(ratingList _rating, studentList _student);

	private:

};

