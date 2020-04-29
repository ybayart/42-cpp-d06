/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:51:20 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 20:32:34 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void
identify_from_reference(Base& p)
{
	A		a;
	B		b;
	C		c;
	char	value[2][sizeof(p)];

	memcpy(&value[0], (void*)&p, sizeof(p));
	memcpy(&value[1], (void*)&a, sizeof(p));
	if (strncmp(value[0], value[1], sizeof(p)) == 0)
		return ((void)(std::cout << "A" << std::endl));
	memcpy(&value[1], (void*)&b, sizeof(p));
	if (strncmp(value[0], value[1], sizeof(p)) == 0)
		return ((void)(std::cout << "B" << std::endl));
	memcpy(&value[1], (void*)&c, sizeof(p));
	if (strncmp(value[0], value[1], sizeof(p)) == 0)
		return ((void)(std::cout << "C" << std::endl));
}

void
identify_from_pointer(Base* p)
{
	identify_from_reference((*p));
}

int
main(void)
{
	A		a;
	B		b;
	C		c;

	identify_from_pointer(&a);
	identify_from_pointer(&b);
	identify_from_pointer(&c);

	identify_from_reference(c);
	identify_from_reference(b);
	identify_from_reference(a);
}
