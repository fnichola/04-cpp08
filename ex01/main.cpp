/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:00:58 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/09 04:13:38 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <climits>
#include "Span.hpp"
#include "debugPrint.hpp"

// generate a random number between 0 and 42
int random42()
{
	return (std::rand() % 43);
}

int main()
{
	srand(std::time(0));

	{
		Span sp(15);

		debugPrint("----- add numbers manually -----");
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();

		debugPrint("----- add numbers using range of iterators -----");
		std::vector<int> v(10);
		std::generate(v.begin(), v.end(), random42);
		sp.addRange(v.begin(), v.end());
		sp.print();

		debugPrint("shortestSpan and longestSpan:");
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		debugPrint("shortestSpan and longestSpan:");
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	{
		debugPrint("----- exceptions -----");
		std::cout << "empty vector:" << std::endl;
		Span sp(5);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		sp.addNumber(1);

		std::cout << "1 element vector: " << std::endl;
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "Add too many numbers" << std::endl;
		try
		{
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			sp.addNumber(5);
			sp.addNumber(6);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


	debugPrint("----- 10,000 numbers -----");
	Span bigSpan(10000);
	std::vector<int> v2(10000);
	std::generate(v2.begin(), v2.end(), random42);
	bigSpan.addRange(v2.begin(), v2.end());
	// bigSpan.print();

	debugPrint("shortestSpan and longestSpan:");
	std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << bigSpan.longestSpan() << std::endl;

	debugPrint("----- 1,000,000 numbers -----");
	Span biggerSpan(1000000);
	std::vector<int> v3(1000000);
	std::generate(v3.begin(), v3.end(), random42);
	biggerSpan.addRange(v3.begin(), v3.end());

	debugPrint("shortestSpan and longestSpan:");
	std::cout << "Shortest Span: " << biggerSpan.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << biggerSpan.longestSpan() << std::endl;


	return 0;
}
