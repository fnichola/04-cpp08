/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:00:04 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/05 04:20:31 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stdlib.h>
#include "easyfind.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "vector:" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::vector<int> v;
	for (size_t i = 0; i < 5; ++i)
	{
		v.push_back(rand() % 5 + 1);
	}
	for (std::vector<int>::iterator it = v.begin(); it < v.end(); ++it)
	{
		std::cout << "v[" << (it - v.begin()) << "] = " << *it << std::endl;
	}

	std::vector<int>::iterator v_result = easyfind(v, 4);
	if (v_result != v.end())
		std::cout << "4 found at index " << (v_result - v.begin()) << std::endl;
	else
		std::cout << "4 not found" << std::endl;


	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "deque:" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	std::deque<int> d;
	for (size_t i = 0; i < 5; ++i)
	{
		d.push_back(rand() % 5 + 1);
	}
	for (std::deque<int>::iterator it = d.begin(); it < d.end(); ++it)
	{
		std::cout << "d[" << (it - d.begin()) << "] = " << *it << std::endl;
	}

	std::deque<int>::iterator d_result = easyfind(d, 4);
	if (d_result != d.end())
		std::cout << "4 found at index " << (d_result - d.begin()) << std::endl;
	else
		std::cout << "4 not found" << std::endl;


	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "list:" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	std::list<int> l;
	for (size_t i = 0; i < 5; ++i)
	{
		l.push_back(rand() % 5 + 1);
	}
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << "l[" << &*it << "] = " << *it << std::endl;
	}

	std::list<int>::iterator l_result = easyfind(l, 4);
	if (l_result != l.end())
		std::cout << "4 found at address " << &*l_result << std::endl;
	else
		std::cout << "4 not found" << std::endl;
	return 0;
}
