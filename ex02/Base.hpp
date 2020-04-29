/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:48:48 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 20:32:09 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string.h>

class	Base
{
	public:
		virtual ~Base(void);
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

#endif
