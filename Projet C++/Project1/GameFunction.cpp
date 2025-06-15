#include <iostream>
#include "GameBoard.cpp"

void Info(Player* player, std::array<int, 2> position) {
	std::cout << "Player is at position: (" << position[0] << ", " << position[1] << ")" << std::endl;
	std::cout << "Player HP: " << player->getHp() << std::endl;
	std::cout << "Player Attack: " << player->getAttack() << std::endl;
	std::cout << "Player Defense: " << player->getDefense() << std::endl;
}

void MoveRight(Entity* entity, Board& board) {
	auto pos = entity->getPosition();
	int newX = pos[0];
	int newY = pos[1] + 1;

	if (newX >= BOARD_SIZE) {
		newX = 0; 
	}
	// Supprime l'entité de l'ancienne position
	board.DeleteEntity(pos[0], pos[1]);

	board.setEntity(newX, newY, entity);
}

void MoveLeft(Entity* entity, Board& board) {
	auto pos = entity->getPosition();
	int newX = pos[0];
	int newY = pos[1] - 1;

	if (newX < 0) {
		newX = BOARD_SIZE - 1;
	}
	// Supprime l'entité de l'ancienne position
	board.DeleteEntity(pos[0], pos[1]);

	board.setEntity(newX, newY, entity);
}

void MoveUp(Entity* entity, Board& board) {
	auto pos = entity->getPosition();
	int newX = pos[0] - 1;
	int newY = pos[1];

	if (newX < 0) {
		newX = BOARD_SIZE - 1;
	}
	// Supprime l'entité de l'ancienne position
	board.DeleteEntity(pos[0], pos[1]);

	board.setEntity(newX, newY, entity);
}

void MoveDown(Entity* entity, Board& board) {
	auto pos = entity->getPosition();
	int newX = pos[0] + 1;
	int newY = pos[1];

	if (newX >= BOARD_SIZE) {
		newX = 0;
	}
	// Supprime l'entité de l'ancienne position
	board.DeleteEntity(pos[0], pos[1]);

	board.setEntity(newX, newY, entity);
}



void run() {
	Board board;
	Player* player = new Player(100,50,10,{0,0});
	std::unique_ptr<Item> item = std::make_unique<Weapon>("Sword", 5, ItemType::WEAPON, WeaponType::SWORD);
	std::cout << "Welcome to the game!" << std::endl;
	std::cout << "Game is running..." << std::endl;
	std::cout << "------------------------" << std::endl;

	board.setEntity(BOARD_SIZE/2, BOARD_SIZE/2, player);
	auto position = player->getPosition();
	DisplayBoard(board);
	Info(player, position);
	player->addItem(std::move(item));
	player->listInventory();
}