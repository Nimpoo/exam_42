/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:05:04 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:52:55 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

# include "ASpell.hpp"

class ATarget {

public:

	ATarget( void );
	virtual ~ATarget( void );
	ATarget( std::string const &type );
	ATarget( ATarget const &src );
	ATarget	&operator=( ATarget const &rhs );

	std::string const &getType( void ) const;

	virtual ATarget	*clone( void ) const = 0;

	void	getHitBySpell( ASpell const &spell ) const;

protected:

	std::string	type;

};

#endif

class ATarget;

