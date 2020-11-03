/*
 * main.cc
 *
 *  Created on: 3 нояб. 2020 г.
 *      Author: Лев
 */
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "ExampleWindow.h"



int main(int, char**){
	std::cout << "Начало main()" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	try {

		ExampleWindow w;

		w.main_loop();

	} catch(std::exception & e){
		std::cerr << "Во время работы программы возникло исключение: "
				<< std::endl
				<<e.what()
				<<std::endl;
		return 1;
	} catch (...){
		std::cerr << "Warning!" << std::endl;
		return 1;
	}
	std::cout << "Конец main()" << std::endl;

	return 0;
}







