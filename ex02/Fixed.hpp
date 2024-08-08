/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:15:44 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/08 16:52:07 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int fixed_point_nbr;
	static const int fractional_bits = 8;

  public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	bool operator>(const Fixed &n2) const;
	bool operator<(const Fixed &n2) const;
	bool operator>=(const Fixed &n2) const;
	bool operator<=(const Fixed &n2) const;
	bool operator==(const Fixed &n2) const;
	bool operator!=(const Fixed &n2) const;

	Fixed operator+(const Fixed &n2) const;
	Fixed operator-(const Fixed &n2) const;
	Fixed operator*(const Fixed &n2) const;
	Fixed operator/(const Fixed &n2) const;

	Fixed &operator++();   // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed &operator--();   // Pre-decrement
	Fixed operator--(int); // Post-decrement

	static Fixed &min(Fixed &n1, Fixed &n2);
	static const Fixed &min(const Fixed &n1, const Fixed &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
	static const Fixed &max(const Fixed &n1, const Fixed &n2);

	int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif