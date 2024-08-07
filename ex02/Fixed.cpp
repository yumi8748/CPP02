/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:15:43 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/07 19:53:49 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():fixed_point_nbr(0){};

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::Fixed(const int n){
	fixed_point_nbr = n << fractional_bits;	
}

Fixed::Fixed(const float f){
	fixed_point_nbr = roundf(f * (1 << fractional_bits));
}

Fixed::~Fixed(){}

Fixed &Fixed::operator = (const Fixed &other){
	if (this != &other)
	{
		fixed_point_nbr = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &n2) const{
	return fixed_point_nbr > n2.fixed_point_nbr;
}

bool Fixed::operator<(const Fixed &n2) const{
	return fixed_point_nbr < n2.fixed_point_nbr;
}
bool Fixed::operator>=(const Fixed &n2) const{
	return fixed_point_nbr >= n2.fixed_point_nbr;
}

bool Fixed::operator<=(const Fixed &n2) const{
	return fixed_point_nbr <= n2.fixed_point_nbr;
}

bool Fixed::operator==(const Fixed &n2) const{
	return fixed_point_nbr == n2.fixed_point_nbr;
}

bool Fixed::operator!=(const Fixed &n2) const{
	return fixed_point_nbr != n2.fixed_point_nbr;
}

Fixed Fixed::operator+(const Fixed &n2) const{
	return Fixed(this->toFloat() + n2.toFloat());
}

Fixed Fixed::operator-(const Fixed &n2) const{
	return Fixed(this->toFloat() - n2.toFloat());
}
Fixed Fixed::operator*(const Fixed &n2) const{
	return Fixed(this->toFloat() * n2.toFloat());	
}

Fixed Fixed::operator/(const Fixed &n2) const{
	//0
	return Fixed(this->toFloat() / n2.toFloat());
}

Fixed &Fixed::operator++();   // Pre-increment
Fixed Fixed::operator++(int); // Post-increment
Fixed &Fixed::operator--();   // Pre-decrement
Fixed Fixed::operator--(int); // Post-decrement

static Fixed &Fixed::min(Fixed &n1, Fixed &n2);
static const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2);
static Fixed &Fixed::max(Fixed &n1, Fixed &n2);
static const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2);

int		Fixed::getRawBits(void) const;
void	Fixed::setRawBits(int const raw);
float	Fixed::toFloat(void) const;
int		Fixed::toInt(void) const;

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);