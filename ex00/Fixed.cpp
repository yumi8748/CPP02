/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:59:55 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/02 17:55:51 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(/* args */)
{
	Fixed::fixed_point_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(/* args */)
{
	std::cout << "Copy constructor calle" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
}

void setRawBits( int const raw )
{}