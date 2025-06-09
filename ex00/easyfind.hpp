/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:08:55 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/28 19:08:56 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     EASYFIND_HPP
# define    EASYFIND_HPP

#include <iostream>
#include <algorithm> //std::find 함수
#include <stdexcept>

template<typename T>
typename T::iterator     easyfind(T& a, int n)
{
      typename T::iterator result = std::find(a.begin(), a.end(), n);
      if (result != a.end()) {
            return (result);
      }
      else {
            throw std::runtime_error("Value not found");
      }
}



#endif