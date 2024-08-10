/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:54 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/10 16:09:05 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(float const x_value, float const y_value);
    Point(const Point &other);
    Point &operator = (const Point &other);
    ~Point();
    const Fixed get_x() const;
    const Fixed get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif