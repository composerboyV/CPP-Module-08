/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:53:04 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/29 12:53:05 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}
Span::~Span()
{
}


Span::Span(unsigned int N) : N(N)
{}


Span::Span(const Span& other)
{
      if (this != &other) {
            this->N = other.N;
            this->number = other.number;
      }
}


Span& Span::operator=(const Span& other)
{
      if (this != &other) {
            this->N = other.N;
            this->number = other.number;
      }
      return (*this);
}


void     Span::addNumber(unsigned int num)
{

      if (this->number.size() >= N) {
            throw std::out_of_range("number had number!");
      }
      number.push_back(num);
}

int  Span::shortestSpan()
{
      std::vector<int> sorted = number;
      std::sort(sorted.begin(), sorted.end());

      int o = 2147483647;
      for(size_t i = 1; i < sorted.size(); i++) {
            int j = sorted[i] - sorted[i - 1];
            if (j < o) {
                  o = j;
            }
      }
      return (o);
}

int  Span::longestSpan()
{
      int   min_value = *std::min_element(number.begin(), number.end());
      int   max_value = *std::max_element(number.begin(), number.end());

      return (max_value - min_value);
}

void   Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
      size_t count = std::distance(begin, end);
      if (number.size() + count > N) 
            throw std::out_of_range("not enough Span");
      number.insert(number.end(), begin, end);
}

