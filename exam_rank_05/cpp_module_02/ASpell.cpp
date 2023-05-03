/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:21:54 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:51:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell( void ) { }
ASpell::ASpell( std::string const &name, std::string const &effects ) : name( name ), effects( effects ) { }
ASpell::ASpell( ASpell const &src ) { *this = src; }
ASpell::~ASpell( void ) { }
ASpell	&ASpell::operator=( ASpell const &rhs ) { if (this != &rhs) {this->name = rhs.name; this->effects = rhs.effects;} return (*this); }

std::string const &ASpell::getName( void ) const { return (this->name); }

std::string const &ASpell::getEffects( void ) const { return (this->effects); }

void	ASpell::launch( ATarget const &target ) const {

	target.getHitBySpell( *this );
}

