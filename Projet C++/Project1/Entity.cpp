#include <iostream>
#include <array>
#include <vector>

enum class EntityType {
	PLAYER,
	MOB,
	VOID
};

enum class ItemType {
	HEAL,
	WEAPON
};

enum class WeaponType {
	SWORD,
	BOW
};

class Item {
private:
	std::string name;
	ItemType type; // Assuming ItemType is an enum for different item types
public:
	Item(const std::string& itemName, ItemType type) : name(itemName), type(type) {}
	virtual ~Item() = default;
	std::string getName() const { return name; }
	void setName(const std::string& newName) { name = newName; }
	ItemType getType() const { return type; }
};

class Entity {
private:
	EntityType type;
	double attack;
	std::array<int,2> Position; // Assuming Position is an array of two integers for x and y coordinates
public:
	Entity(EntityType t, double hp, double attack, std::array<int,2> pos) : 
		type(t), hp(hp), attack(attack), Position(pos){}
	double hp;
	double getHp() const { return hp; }
	double getAttack() const { return attack; }
	void setHp(double newHp) { hp = newHp; }
	void setAttack(double newAttack) { attack = newAttack;}

	void setPosition(int x, int y) {
		if (x < 0 || y < 0) {
			std::cout << "Position cannot be negative. Setting to (0, 0)." << std::endl;
			Position = { 0,0 };
		}
		else {
			Position = { x, y };
		}
	}

	std::array<int, 2> getPosition() {
		return Position; 
	}

	EntityType getType() const { return type; }
	virtual ~Entity() = default; // Virtual destructor for proper cleanup in derived classes
};

class Player : public Entity {
private:
	double defense;
	std::vector<std::unique_ptr<Item>> inventory; // Assuming Item is a class defined elsewhere
	static constexpr size_t INVENTORY_SIZE = 5;
public:
	Player() : Entity(EntityType::PLAYER,100, 10,{0,0}), defense(5) {} // Default constructor
	Player(double hp, double attack, double defense,std::array<int,2> pos) : Entity(EntityType::PLAYER,hp, attack,pos),
		defense(defense) {} // Parameterized constructor
	double getDefense() const { return defense; }
	void setDefense(double newDefense) { 
		if (newDefense < 0) {
			std::cerr << "Defense cannot be negative. Setting to 0." << std::endl;
			newDefense = 0;
		}
		defense = newDefense; }

	void listInventory() const {
		std::cout << "Inventory: " << std::endl;
		for (const auto& item : inventory) {
			std::cout << "- " << item->getName() << std::endl;
		}
	}

	void addItem(std::unique_ptr<Item> item) {
		if (inventory.size() < INVENTORY_SIZE) {
			inventory.push_back(std::move(item));
		}
		else {
			std::cerr << "Inventory is full. Cannot add more items." << std::endl;
		}
	}
};

class Mob : public Entity {
public:
	Mob() : Entity(EntityType::MOB,50, 5,{0,0}) {} // Default constructor
	Mob(double hp, double attack,std::array<int,2> pos) : Entity(EntityType::MOB,hp, attack,pos) {} // Parameterized constructor
};

class Void : public Entity {
public:
	explicit Void(const std::array<int, 2>& pos = { 0, 0 })
		: Entity(EntityType::VOID, 0, 0, pos) {}
};

class Heal : public Item {
private:
	double healAmount;
public:
	Heal(const std::string& itemName, double amount, ItemType type) : Item(itemName,type), healAmount(amount) {
		if (amount < 0) {
			std::cerr << "Heal amount cannot be negative. Setting to 0." << std::endl;
			healAmount = 0;
		}
	}
	double getHealAmount() const { return healAmount; }
	void setHealAmount(double newAmount) {
		if (newAmount < 0) {
			std::cerr << "Heal amount cannot be negative. Setting to 0." << std::endl;
			newAmount = 0;
		}
		healAmount = newAmount;
	}
};

class Weapon : public Item {
private:
	double attackPoints;
	WeaponType weaponType; // Assuming WeaponType is an enum for different weapon types
public:
	Weapon(const std::string& itemName, double attack, ItemType type,WeaponType Wtype) : Item(itemName,type), attackPoints(attack)
	, weaponType(Wtype) 
	{
		if (attack < 0) {
			std::cerr << "Attack points cannot be negative. Setting to 0." << std::endl;
			attackPoints = 0;
		}
	}
	double getAttackPoints() const { return attackPoints; }
	void setAttackPoints(double newAttack) {
		if (newAttack < 0) {
			std::cerr << "Attack points cannot be negative. Setting to 0." << std::endl;
			newAttack = 0;
		}
		attackPoints = newAttack;
	}
	WeaponType getWeaponType() const { return weaponType; }
};
