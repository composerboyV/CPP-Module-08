/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:52:55 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/29 12:52:56 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <iostream>
#include <stdio.h>
int main()
{
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
// 여기서부터 추가 테스트 코드
std::cout << "\n=== 추가 테스트 ===" << std::endl;
try {
    // 가득 찬 Span에 추가 테스트
    sp.addNumber(42);
} catch (const std::exception& e) {
    std::cout << "예외 발생: " << e.what() << std::endl;
}

// 큰 Span 테스트
Span largeSpan(10000);
std::vector<int> numbers;

// 벡터에 숫자 채우기
for (int i = 0; i < 10000; i++) {
    numbers.push_back(rand() % 1000000);
}

// addRange 테스트
largeSpan.addRange(numbers.begin(), numbers.end());

std::cout << "Large span - shortest: " << largeSpan.shortestSpan() << std::endl;
std::cout << "Large span - longest: " << largeSpan.longestSpan() << std::endl;

return 0;
}
