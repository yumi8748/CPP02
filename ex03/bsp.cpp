/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:47 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/10 17:18:24 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 计算叉积
Fixed crossProduct(Point const &p1, Point const &p2, Point const &p3) {
    return (p2.get_x() - p1.get_x()) * (p3.get_y() - p1.get_y()) -
           (p2.get_y() - p1.get_y()) * (p3.get_x() - p1.get_x());
}

// 判断点是否在三角形内
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    bool has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);
    bool has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);

    return !(has_neg && has_pos);
}