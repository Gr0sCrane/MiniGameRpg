#include <iostream>
#include "Actions.cpp"

// Ce fichier va generer le plateau de jeu

// |Const variables|***************************************
const char letter[20] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'
};
const int BOARD_SIZE = 20;
//********************************************************

class Board {
private:
	Entity* board[BOARD_SIZE][BOARD_SIZE];
public:
	Board() {
		for (int i = 0; i < BOARD_SIZE; ++i) {
			for (int j = 0; j < BOARD_SIZE; ++j) {
				board[i][j] = new Void({ i,j });  // Initialise chaque case avec une entité de type Void
			}
		}
	}
	~Board() {
		for (int i = 0; i < BOARD_SIZE; ++i) {
			for (int j = 0; j < BOARD_SIZE; ++j) {  // Libère chaque entité
				board[i][j] = nullptr; // Bonne pratique
				delete board[i][j];
			}
		}
	}

	void setEntity(int x, int y, Entity* entity) {
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
			board[x][y] = entity;
			entity->setPosition(x, y);  // Met à jour la position de l'entité
		}
		else {
			delete entity;
		}
	}

	void DeleteEntity(int x, int y) {
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
			board[x][y] = new Void({ x,y });  // Remplace par une entité de type Void
		}
	}

	EntityType getEntityType(int x, int y) const {
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
			return board[x][y]->getType();
		}
		return EntityType::VOID;
	}

};

void DisplayLetter() {
	for (int i = 0; i < 20; ++i) {
		std::cout << " " << letter[i] << " ";
	}
	std::cout << std::endl;
}

void DisplayBoard(Board& board) {
	int count = 0;
	std::cout << "This is the game board" << std::endl;
	std::cout << "------------------------" << std::endl;
	DisplayLetter();
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			switch (board.getEntityType(i, j)) {
			case EntityType::VOID:   
				std::cout << "[ ]"; break;
			case EntityType::PLAYER: 
				std::cout << "|P|"; break;
			case EntityType::MOB:    
				std::cout << "|M|"; break;
			default:                
				std::cout << "[?]"; break;
			}
		}
		std::cout << count;
		std::cout<<std::endl;
		count++;
	}
}