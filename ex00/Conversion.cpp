/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:46:54 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:51:45 by hexa             ###   ########.fr       */
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

int
Conversion::m_getPrecision(void) const
{
	unsigned int	before;
	unsigned int	after;

	before = 0;
	while (this->m_str[before] && this->m_str[before] != '.')
		before += 1;
	after = before + 1;
	while (this->m_str[after] && isdigit(this->m_str[after]))
		after += 1;
	after -= before;
	return ((this->m_str.size() == before || after == 1) ? 1 : after - 1);
}

Conversion::operator char() const
{
	int		nb;
	long	tmp;
	char*	end;

	try
	{
		tmp = std::strtod(this->m_str.c_str(), &end);
		nb = tmp;
		if (tmp < INT_MIN || tmp > INT_MAX)
			throw std::exception();
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
	long	tmp;
	char*	end;

	try
	{
		tmp = std::strtod(this->m_str.c_str(), &end);
		nb = tmp;
		if (tmp < INT_MIN || tmp > INT_MAX)
			throw std::exception();
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
	char*	end;

	try
	{
		nb = std::strtod(this->m_str.c_str(), &end);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	std::cout << std::setprecision(this->m_getPrecision()) << std::fixed;
	return (nb);
}

Conversion::operator double() const
{
	double	nb;
	char*	end;

	try
	{
		nb = std::strtod(this->m_str.c_str(), &end);
	}
	catch (std::exception& e)
	{
		throw (Conversion::ConversionErrorException());
	}
	std::cout << std::setprecision(this->m_getPrecision()) << std::fixed;
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

