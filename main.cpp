#include "library.h"

// Объявление классов
#include "studentList.h"
#include "groupList.h"
#include "disciplineList.h"


//public: // Публичная область класса
//
//private: // Закрытая область класса

// Создать класс DB 
// В нем будет вся инфа
// Классы это интерфейс управления DB


// Создавать класс и отправлять его в метод


int main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	groupList group;
	studentList student;
	disciplineList discipline;


	group.read();


	student.read(group);
	student.output();

	student.create(group);
	student.output();


	group.output();
	group.remove(1, student);

	system("pause");
	return 0;
}