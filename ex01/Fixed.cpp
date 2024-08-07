/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:15:35 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/07 17:15:36 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():fixed_point_nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
    std::cout << "Int constructor called" << std::endl;
    fixed_point_nbr = n << fractional_bits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    fixed_point_nbr = static_cast<int>(roundf(f * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor calle" << std::endl;
	*this = other;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point_nbr = other.fixed_point_nbr;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_nbr);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_nbr = raw;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(fixed_point_nbr) / (1 << fractional_bits);
}

int Fixed::toInt(void) const{
    return fixed_point_nbr >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return (os);
}