/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:33:31 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:53:52 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget( "Target Practice Dummy" ) { }
Dummy::~Dummy( void ) { }

ATarget	*Dummy::clone( void ) const { return ( new Dummy() ); }

