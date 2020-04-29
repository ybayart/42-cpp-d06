/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:46:20 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 19:33:11 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int
main(void)
{
	void*	raw;
	Data*	data;

	raw = serialize();
	data = deserialize(raw);
	std::cout << "main:" << std::endl <<
				"s1: " << (*data).s1 << std::endl <<
				" n: " << (*data).n << std::endl <<
				"s2: " << (*data).s2 << std::endl;
}
