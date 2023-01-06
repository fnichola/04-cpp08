/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:03:54 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/06 03:07:13 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int size);
	Span(const Span &src);
	~Span();
	Span &operator=(const Span &rhs);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

private:
	std::vector<int> m_vector;
	unsigned int m_maxSize;
};
