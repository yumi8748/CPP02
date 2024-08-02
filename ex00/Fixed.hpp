/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:59:47 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/02 17:50:32 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	fixed_point_nbr;
	static const int fractional_bits;
public:
	Fixed(/* args */);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};




#endif