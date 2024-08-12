/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumi <yumi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:51 by yu-chen           #+#    #+#             */
/*   Updated: 2024/08/12 14:14:30 by yumi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// int main() {
//     Point a(0, 0);
//     Point b(10, 0);
//     Point c(0, 10);
//     Point p(0, 10);

//     if (bsp(a, b, c, p)) {
//         std::cout << "Point is inside the triangle" << std::endl;
//     } else {
//         std::cout << "Point is outside the triangle" << std::endl;
//     }

//     return 0;
// }

// int main() {
//     Point a(0, 0);
//     Point b(4, 0);
//     Point c(2, 4);

//     // Test Case 1: Point inside the triangle
//     Point p(2, 2);

//     std::cout << bsp(a, b, c, p) << std::endl;

//     // Test Case 2: Point outside the triangle
//     Point p2(5, 2);
//     std::cout << bsp(a, b, c, p2) << std::endl;

//     // Test Case 3: Point on the edge of the triangle
//     Point p3(1, 0);
//     std::cout << bsp(a, b, c, p3) << std::endl;

//     return 0;
// }

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point p(1, 8);

    std::cout << "Return of bsp:" << bsp(a, b, c, p) << std::endl;
    if (bsp(a, b, c, p)) {
        std::cout << "Point is inside the triangle" << std::endl;
    } else {
        // 进一步判断点是否在三角形的边上或顶点上
        if (p == a || p == b || p == c) {
            std::cout << "Point is on a vertex of the triangle" << std::endl;
        } else {
            Fixed cp1 = crossProduct(a, b, p);
            Fixed cp2 = crossProduct(b, c, p);
            Fixed cp3 = crossProduct(c, a, p);

            if (cp1 == 0 || cp2 == 0 || cp3 == 0) {
                std::cout << "Point is on the edge of the triangle" << std::endl;
            } else {
                std::cout << "Point is outside the triangle" << std::endl;
            }
        }
    }

    return 0;
}