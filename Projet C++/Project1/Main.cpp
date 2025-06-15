#include <iostream>
#include"GameFunction.cpp"

int main(){

	bool isGameRunning = true;

	while (isGameRunning) {
		run();
		return false; // Juste pour pas faire une boucle infinie
	}
	return 0;
}