/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:03:15 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:54:38 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <cstdlib>

struct	Data
{
	std::string s1;
	int			n;
	std::string	s2;
};

void*	serialize(void);
Data*	deserialize(void*);

class	Serialization
{
	private:
		void*	m_raw;

	public:
		Serialization(void);
		Serialization(void*);
		Serialization(const Serialization&);
		Serialization& operator=	(const Serialization&);

		~Serialization(void);

		operator Data*() const;
};

#endif
