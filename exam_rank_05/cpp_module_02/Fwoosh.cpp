/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:33:31 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:36:52 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) : ASpell( "Fwoosh", "fwooshed" ) { }
Fwoosh::~Fwoosh( void ) { }

ASpell	*Fwoosh::clone( void ) const { return ( new Fwoosh() ); }

