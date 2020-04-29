/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:59:43 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 17:18:58 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

static void
conversion_char(Conversion str)
{
	char	result;

	try
	{
		result = static_cast<char>(str);
		if (result < 32 || result > 126)
			std::cout << "Non displayable";
		else
			std::cout << result;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

static void
conversion_int(Conversion str)
{
	int		result;

	try
	{
		result = static_cast<int>(str);
		std::cout << result;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

static void
conversion_float(Conversion str)
{
	float	result;

	try
	{
		result = static_cast<float>(str);
		std::cout << result << "f";
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

static void
conversion_double(Conversion str)
{
	double	result;

	try
	{
		result = static_cast<double>(str);
		std::cout << result;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

static void
conversion(Conversion str)
{
	std::cout << "char:	";
	conversion_char(str);
	std::cout << std::endl;
	std::cout << "int:	";
	conversion_int(str);
	std::cout << std::endl;
	std::cout << "float:	";
	conversion_float(str);
	std::cout << std::endl;
	std::cout << "double:	";
	conversion_double(str);
	std::cout << std::endl;
}

int
main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "You must enter a value to convert" << std::endl;
		return (1);
	}

	Conversion	str(argv[1]);
	conversion(str);
	return (0);
}
