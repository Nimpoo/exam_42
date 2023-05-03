/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:32:52 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 19:50:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

# include <map>
# include <algorithm>

# include "ATarget.hpp"
# include "ASpell.hpp"

class Warlock {

public:

	Warlock( std::string const &name, std::string const &title );
	~Warlock( void );

	std::string const &getName( void ) const;
	std::string const &getTitle( void ) const;
	void	setTitle( std::string const &title );

	void	introduce( void ) const;

	void	learnSpell( ASpell const *spell );
	void	forgetSpell( std::string const &spellName );
	void	launchSpell( std::string const &spellName, ATarget const &target );

private:

	Warlock( void );
	Warlock( Warlock const &src );
	Warlock	&operator=( Warlock const &rhs );

	std::string	name;
	std::string	title;

	std::map<std::string, ASpell *>	magie;

};

#endif

