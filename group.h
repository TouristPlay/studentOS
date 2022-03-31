#include "library.h"
#include "session.h"

class disciplineList;
class groupList;
class studentList;

class group {

	public:

		// Конструктор класса
		group(string newGroup, string newCourse, string newSpeciality);

		// Конструктор класса
		group();

		// Метод для получения курса группы
		string getCourse();

		// Метод для получения номера группы
		string getGroup();

		// Мето для получения специальности группы
		string getSpeciality();

		// Метод для получения ID
		unsigned getID();

		// Метод для изменения курса группы
		void setCourse(string newCourse);

		// Метод для изменения номера группы
		void setGroup(string newGroup);

		// Мето для изменения специальности группы
		void setSpeciality(string newSpeciality);

		// Метод для вывода дисциплин для сдачи
		bool getDiscipline();

	private:	

		// Курс круппы
		string course;
		// Номер группы
		string groupNumber;
		// Имя специальности
		string speciality;
		// ID
		unsigned ID;
		// Генератор ID
		static unsigned idGenerator;

		// Список дисциплин для сдачи
		vector <session> _session; 

		friend groupList;
		friend studentList;
};

