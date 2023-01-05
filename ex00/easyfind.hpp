/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:38:53 by fnichola          #+#    #+#             */
/*   Updated: 2023/01/05 03:37:19 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T & haystack, int needle)
{
	return std::find(haystack.begin(), haystack.end(), needle);
}
