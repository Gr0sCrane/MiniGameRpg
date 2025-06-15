#include <iostream>
#include <random>
#include "Entity.cpp"

const double FULLHP = 100.0;

void attack(double damage, Player target) {

	double EffectiveDamage = damage - (target.getDefense() / 100.0);

	if (EffectiveDamage < 0)
		damage = 0;
	else
		damage = EffectiveDamage;

	target.hp -= damage;
}

void attack(double damage, Mob target) {
	target.hp -= damage;
}

void GetHealth(double heal, Entity target) {
	if (heal > 0) {
		target.hp += heal;
	}
	else
	{
		std::cout << "Heal amount is incorrect" << std::endl;
	}
}

void GetFullHp(Entity target) {
	target.hp = FULLHP;
}
