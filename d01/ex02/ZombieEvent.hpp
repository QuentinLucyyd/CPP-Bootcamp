/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:28:33 by qmanamel          #+#    #+#             */
/*   Updated: 2018/06/06 08:28:39 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {
	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		void setZombieType(std::string _type);
		Zombie* newZombie(std::string _name);
		Zombie* randomChump();
	private:
		std::string type;
};
#endif
