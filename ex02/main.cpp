/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:51:20 by hexa              #+#    #+#             */
/*   Updated: 2020/05/09 18:23:46 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void
identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "0" << std::endl;
}

void
identify_from_reference(Base& p)
{
	identify_from_pointer((&p));
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
