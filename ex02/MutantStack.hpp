/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:22:59 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/30 09:23:00 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     MUTANTSTACK_HPP
# define    MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template<typename T>
class MutantStack : public std::stack<T>
{
public:
      MutantStack(/* args */);
      ~MutantStack();
      MutantStack(const MutantStack& other);
      MutantStack<T>& operator=(const MutantStack& other);
      typedef typename  std::stack<T>::container_type::iterator  iterator;
      typedef typename  std::stack<T>::container_type::const_iterator   const_iterator;
      iterator    begin();
      iterator    end();
      const_iterator    begin() const;
      const_iterator    end() const;
};

// #ifndef     MUTANTSTACK_TPP
// # define    MUTANTSTACK_TPP
# include "MutantStack.tpp"
// #endif

#endif