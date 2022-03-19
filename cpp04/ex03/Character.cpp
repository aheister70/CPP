/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: annaheister <annaheister@student.codam.nl>   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 08:38:48 by annaheister   #+#    #+#                 */
/*   Updated: 2022/02/23 08:38:48 by annaheister   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void) : _amount(0) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_lostInventory = nullptr;
	return;
}

Character::Character(std::string name) : _name(name), _amount(0) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	this->_lostInventory = nullptr;
	return;
}

Character::Character(Character const & src) {
	this->_name = src._name;
	for (int i = 0; i < this->_amount; i++)
		delete this->_inventory[i];
	this->_amount = 0;
	for (int i = 0; i < 4 ; i++)
		this->_inventory[i] = nullptr;
	for (int i = 0; i < src._amount ; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
		this->_amount += 1;
	}
	return;
}

Character& Character::operator=(Character & rhs) {
	this->_name = rhs._name;
	for (int i = 0; i < this->_amount; i++)
		delete this->_inventory[i];
	this->_amount = 0;
	for (int i = 0; i < 4 ; i++)
		this->_inventory[i] = nullptr;
	for (int i = 0; i < rhs._amount ; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
		this->_amount += 1;
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < this->_amount; i++)
		delete this->_inventory[i];
	if (this->_lostInventory != NULL) {
		delete this->_lostInventory;
	}
	return;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* materia) {
	if (this->_amount < 4 && materia != nullptr) {
		if (this->_amount == 0)
			this->_inventory[0] = materia;
		else
			this->_inventory[_amount] = materia;
		this->_amount += 1;
	}
	if (this->_lostInventory != NULL) {
		delete this->_lostInventory;
		this->_lostInventory = nullptr;
	}
}

/*
 * With unequip the Materia is not deleted but just removed from the inventory.
 * Therefore the pointer of the removed Materia should be stored. This is done
 * in the _lostInventory. The stored _lostInventory will be removed either when a
 * character is equiped with new Materia or when a character is deleted.
 */

void Character::unequip(int idx) {
	for (int i = 0; i < this->_amount; i++) {
		if (i == idx) {
			this->_lostInventory = this->_inventory[idx];
			while (idx < this->_amount) {
				this->_inventory[idx] = this->_inventory[idx + 1];
				idx += 1;
			}
			this->_amount -= 1;
			this->_inventory[3] = nullptr;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	this->_inventory[idx]->use(target);
}
