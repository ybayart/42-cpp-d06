/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:03:15 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 19:00:37 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <string.h>

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

		explicit operator Data*() const;
};

#endif
