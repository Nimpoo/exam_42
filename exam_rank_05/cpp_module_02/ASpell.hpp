/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:57:41 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:53:11 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

class ASpell {

public:

	ASpell( void );
	virtual ~ASpell( void );
	ASpell( std::string const &name, std::string const &effects );
	ASpell( ASpell const &src );
	ASpell	&operator=( ASpell const &rhs );

	std::string const &getName( void ) const;
	std::string const &getEffects( void ) const;

	virtual ASpell	*clone( void ) const = 0;

	void	launch( ATarget const &target ) const;

protected:

	std::string	name;
	std::string	effects;

};

#endif

class ASpell;

