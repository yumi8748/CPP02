/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:15:43 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/08 16:36:45 by yu-chen          ###   ########.fr       */
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
	if (n2.fixed_point_nbr == 0)
		throw ("cannot be diveded by 0");//error
	return Fixed(this->toFloat() / n2.toFloat());
}

Fixed &Fixed::operator++(){
	this->fixed_point_nbr++;
	return *this;
}   // Pre-increment
Fixed Fixed::operator++(int){
	Fixed	tmp(*this);
	this->fixed_point_nbr += 1;
	return (tmp);
} // Post-increment
Fixed &Fixed::operator--(){
	this->fixed_point_nbr--;
	return (*this);
}   // Pre-decrement
Fixed Fixed::operator--(int){
	Fixed	tmp(*this);
	this->fixed_point_nbr -= 1;
	return (tmp);
} // Post-decrement

Fixed &Fixed::min(Fixed &n1, Fixed &n2){
	return ((n1 < n2) ? n1 : n2);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2){
	return ((n1 < n2) ? n1 : n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2){
	return ((n1 > n2) ? n1 : n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2){
	return ((n1 > n2) ? n1 : n2);
}

int		Fixed::getRawBits(void) const{
	return (this->fixed_point_nbr);
}
void	Fixed::setRawBits(int const raw){
	this->fixed_point_nbr = raw;
}

float	Fixed::toFloat(void) const{
	return static_cast<float>(fixed_point_nbr) / (1 << fractional_bits);
}

int		Fixed::toInt(void) const{
	return fixed_point_nbr >> fractional_bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed){
	os << fixed.toFloat();
	return (os);
}
