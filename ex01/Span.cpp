/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:16:23 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/06 03:07:27 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <algorithm>
#include <numeric>
#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int size) : m_maxSize(size) {}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(const Span &rhs)
{
	m_vector = rhs.m_vector;
	return *this;
}

void Span::addNumber(int num)
{
	if (m_vector.size() == m_maxSize)
		throw std::out_of_range("Error: Span is full");
	m_vector.push_back(num);
}

int Span::shortestSpan()
{
	if (m_vector.size() < 2)
		throw std::logic_error("Error: Not enough numbers to compare");
	std::sort(m_vector.begin(), m_vector.end());
	std::vector<int> dVector(m_vector.size() - 1);
	std::adjacent_difference(m_vector.begin(), m_vector.end(), dVector.begin());

	const std::vector<int>::const_iterator minElement =
		std::min_element(dVector.begin() + 1, dVector.end());

	return *minElement;
}

int Span::longestSpan()
{
	if (m_vector.size() < 2)
		throw std::logic_error("Error: Not enough numbers to compare");
	
	const std::vector<int>::const_iterator maxElement = 
		std::max_element(m_vector.begin(), m_vector.end());
	
	const std::vector<int>::const_iterator minElement = 
		std::min_element(m_vector.begin(), m_vector.end());

	return (*maxElement - *minElement);
}

