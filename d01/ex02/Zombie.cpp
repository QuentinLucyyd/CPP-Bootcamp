/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:28:00 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/06 08:24:12 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string _name, std::string _type) : name(_name), type(_type) {return;}
Zombie::~Zombie(void){return;};

void Zombie::announce(void) {
	std::cout << "<" << Zombie::name;
	std::cout << " (" << Zombie::type;
	std::cout << ")> Braiiiiiiiins....." << std::endl;
}
