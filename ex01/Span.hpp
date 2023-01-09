/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:03:54 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/09 03:28:11 by fnichola         ###   ########.fr       */
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

	template< class InputIt >
	void addRange(const InputIt &first, const InputIt &last)
	{
		for (InputIt it = first; it < last; ++it)
		{
			addNumber(*it);
		}
	}

	int shortestSpan();
	int longestSpan();
	void print();

private:
	std::vector<int> m_vector;
	unsigned int m_maxSize;
};
