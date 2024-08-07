/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:59:47 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/05 15:08:15 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	fixed_point_nbr;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &other);
	~Fixed();
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};




#endif