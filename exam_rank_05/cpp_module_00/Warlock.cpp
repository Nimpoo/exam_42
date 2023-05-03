/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:38:45 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 13:52:14 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock( void ) {}

Warlock::Warlock( std::string const &name, std::string const &title ) : name( name ), title( title ) {

	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock( Warlock const &src ) { *this = src; }

Warlock	&Warlock::operator=( Warlock const &rhs ) {

	if (this!= &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return (*this);
}

Warlock::~Warlock( void ) { std::cout << this->name << ": My job here is done!" << std::endl; }

std::string const &Warlock::getName( void ) const { return (this->name); }

std::string const &Warlock::getTitle( void ) const { return (this->title); }

void	Warlock::setTitle( std::string const &title ) { this->title = title; }

void	Warlock::introduce( void ) const {

	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

