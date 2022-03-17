#include "library.h"


class deliveryDisciplines;
class studentList;
class reports;

// Класс учета успеваемости
class ratingList {

	public:

		// Метод для добавления оценок студенту
		bool create(string group, deliveryDisciplines _disciplineList, studentList _studentList);

	private:

		struct rating
		{
			string discipline;
			string grade;
		};

		rating _ratingInfo;

		// Метод для поиска студентов опредленной группы
		void findStudent(string group, studentList _studentList);

		// Метод проверяет есть ли такая дисциплина

		// Метод получения имени студента по ID 
		string getStudentNameByID(int id, studentList _studentList);

		// Метод добавляет всех студентов и дисциплины в список
		bool insertAllStudent(string group, deliveryDisciplines _disciplineList, studentList _studentList);


		map<string, map<string, vector<rating>>> _ratingList;
		//map<группа, map<студент, vector<дисциплина, оценка>>

		friend reports;
};


