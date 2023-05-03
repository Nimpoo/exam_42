/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:32:52 by mayoub            #+#    #+#             */
/*   Updated: 2023/05/03 13:50:00 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock {

public:

	Warlock( std::string const &name, std::string const &title );
	~Warlock( void );

	std::string const &getName( void ) const;
	std::string const &getTitle( void ) const;
	void	setTitle( std::string const &title );

	void	introduce( void ) const;

private:

	Warlock( void );
	Warlock( Warlock const &src );
	Warlock	&operator=( Warlock const &rhs );

	std::string	name;
	std::string	title;

};

#endif

