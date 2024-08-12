/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:53 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/12 13:52:09 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){};

Point::Point(float const x_value, float const y_value): x(x_value), y(y_value) {}

Point::Point(const Point &other): x(other.x), y(other.y){}

//Point &operator = (const Point &other);

Point::~Point(){};

Fixed const  Point::get_x() const{
    return this->x;
}

Fixed const  Point::get_y() const{
    return this->y;
}

bool Point::operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
}


