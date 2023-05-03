/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:14:17 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:51:59 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget( void ) { }
ATarget::ATarget( std::string const &type ) : type( type ) { }
ATarget::ATarget( ATarget const &src ) { *this = src; }
ATarget::~ATarget( void ) { }
ATarget	&ATarget::operator=( ATarget const &rhs ) { if (this != &rhs) this->type = rhs.type; return (*this); }

std::string const &ATarget::getType( void ) const { return (this->type); }

void	ATarget::getHitBySpell( ASpell const &spell ) const {

	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}

