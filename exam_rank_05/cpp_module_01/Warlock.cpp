/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:38:45 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:59:41 by mayoub           ###   ########.fr       */
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

Warlock::~Warlock( void ) { std::cout << this->name << ": My job here is done!" << std::endl;

	std::map<std::string, ASpell *>::iterator	it = this->magie.begin();

	while (it != this->magie.end())
	{
		delete it->second;
		it++;
	}
	this->magie.clear();
}

std::string const &Warlock::getName( void ) const { return (this->name); }

std::string const &Warlock::getTitle( void ) const { return (this->title); }

void	Warlock::setTitle( std::string const &title ) { this->title = title; }

void	Warlock::introduce( void ) const {

	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell( ASpell const *spell ) {

	if (spell)
		this->magie.insert( std::pair<std::string, ASpell *>( spell->getName(), spell->clone() ) );
}

void	Warlock::forgetSpell( std::string const &spellName ) {

	std::map<std::string, ASpell *>::iterator	it_find = this->magie.find(spellName);

	if (it_find != this->magie.end())
		delete it_find->second;
	this->magie.erase(spellName);
}

void	Warlock::launchSpell( std::string const &spellName, ATarget const &target ) {

	ASpell	*spell = this->magie[ spellName ];

	if (spell)
		spell->launch( target );
}

