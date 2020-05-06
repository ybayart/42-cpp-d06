/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:05:07 by hexa              #+#    #+#             */
/*   Updated: 2020/05/05 19:33:43 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization(void)
{
	this->m_raw = NULL;
}

Serialization::Serialization(void* raw)
{
	this->m_raw = raw;
}

Serialization&
Serialization::operator=	(const Serialization& rhs)
{
	if (this != &rhs)
		this->m_raw = rhs.m_raw;
	return (*this);
}

Serialization::~Serialization(void) {}

Serialization::operator Data*() const
{
	Data	*data = new Data;
	char	*input = reinterpret_cast<char*>(this->m_raw);
	
	for (int i = 0;i < 8;i++)
		(*data).s1 += input[i];
	(*data).n = *reinterpret_cast<int*>(input + 8);
	for (int i = 0;i < 8;i++)
		(*data).s2 += input[i + 12];
	return (data);
}

void*
serialize(void)
{
	char*	str = new char[20];
	char	alpha[63] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		n;
	
	for (int i = 0;i < 8;i++)
		str[i] = alpha[rand() % 62];
	n = rand() % 4294967296 - 2147483647;
	*reinterpret_cast<int*>(str + 8) = n;
	for (int i = 0;i < 8;i++)
		str[i + 12] = alpha[rand() % 62];

	std::cout << "Serialize:" << std::endl;
	std::cout << " - ";
	for (int i = 0;i < 8;i++)
		std::cout << str[i];
	std::cout << std::endl << " - ";
	std::cout << n;
	std::cout << std::endl << " - ";
	for (int i = 0;i < 8;i++)
		std::cout << str[i + 12];
	std::cout << std::endl << std::endl;
	return (str);
}

Data*
deserialize(void* raw)
{
	Serialization	obj(raw);
	Data*			data;

	data = static_cast<Data*>(obj);
	return (data);
}
