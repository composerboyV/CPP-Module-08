/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:59 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/29 12:53:01 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     SPAN_HPP
# define    SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
private:
      unsigned int   N;
      std::vector<int> number;
public:
      Span(void);
      Span(unsigned int N);
      ~Span();
      Span(const Span& other);
      Span& operator=(const Span& other);
      void  addNumber(unsigned int num);
      int  shortestSpan();
      int  longestSpan();
      void  addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif