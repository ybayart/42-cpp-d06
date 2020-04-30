/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:35:14 by hexa              #+#    #+#             */
/*   Updated: 2020/04/30 16:03:39 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>

class	Conversion
{
	private:
		std::string	m_str;
		int			m_getPrecision(void) const;
	
	public:
		Conversion(void);
		Conversion(std::string);
		Conversion(const Conversion&);
		Conversion& operator=	(const Conversion&);

		virtual ~Conversion(void);

		void	setStr(std::string);

		explicit operator char() const;
		explicit operator int() const;
		explicit operator float() const;
		explicit operator double() const;

		class ConversionErrorException : public std::exception
		{
		   public:
				ConversionErrorException(void);
				ConversionErrorException(const ConversionErrorException&);

				virtual ~ConversionErrorException(void) throw();

				ConversionErrorException& operator=	(const ConversionErrorException&);

				virtual const char	*what() const throw();
		};
};

#endif
