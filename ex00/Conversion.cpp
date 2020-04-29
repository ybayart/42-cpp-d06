/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:46:54 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 17:17:12 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void) {}

Conversion::Conversion(std::string str)
{
	this->m_str = str;
}

Conversion::Conversion(const Conversion& src)
{
	*this = src;
}

Conversion&
Conversion::operator=	(const Conversion& rhs)
{
	if (this != &rhs)
	{
		this->m_str = rhs.m_str;
	}
	return (*this);
}

Conversion::~Conversion(void) {}

void
Conversion::setStr(std::string str)
{
	this->m_str = str;
}

Conversion::operator char() const
{
	int		nb;

	try
	{
		nb = std::stoi(this->m_str);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	return (nb);
}

Conversion::operator int() const
{
	int		nb;

	try
	{
		nb = std::stoi(this->m_str);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	return (nb);
}

Conversion::operator float() const
{
	float	nb;

	try
	{
		nb = std::stof(this->m_str);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	return (nb);
}

Conversion::operator double() const
{
	double	nb;

	try
	{
		nb = std::stod(this->m_str);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	return (nb);
}



//========== EXCEPTIONS

Conversion::ConversionErrorException::ConversionErrorException(void) {}

Conversion::
ConversionErrorException::ConversionErrorException(const ConversionErrorException& src)
{
    *this = src;
}

Conversion::ConversionErrorException::~ConversionErrorException(void) throw() {}

Conversion::ConversionErrorException&
Conversion::ConversionErrorException::operator=	(const ConversionErrorException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Conversion::ConversionErrorException::what() const throw()
{
    return ("impossible");
}

