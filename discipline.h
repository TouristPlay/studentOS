#pragma once
#include "library.h"


class discipline {

	public:
		// Конструктор
		discipline(string newName);

		discipline();

		// Метод для получения имени дисциплины
		string getName();

		// Метод для получения ID дисциплины
		unsigned getID();

		// Метод для изменения имени ID
		void setName(string newName);

	private:

		string name; // Имя дисциплины 
		unsigned ID; // ID
		// Генератор ID
		static unsigned idGenerator;
};

