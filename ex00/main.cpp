/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:08:45 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/28 19:08:46 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

// 테스트 결과를 깔끔하게 출력하기 위한 헬퍼 함수
template <typename T>
void runTest(T& container, int valueToFind, const std::string& containerName) {
    std::cout << "=== " << containerName << " 테스트 ===" << std::endl;
    
    try {
        // 컨테이너 내용 출력
        std::cout << "컨테이너 내용: ";
        for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        // easyfind 함수 호출
        std::cout << "찾는 값: " << valueToFind << std::endl;
        typename T::iterator found = easyfind(container, valueToFind);
        
        // 값을 찾은 경우
        std::cout << "결과: 값을 찾았습니다! 위치: ";
        // 값의 위치(인덱스) 계산 및 출력
        int position = std::distance(container.begin(), found);
        std::cout << position << " (값: " << *found << ")" << std::endl;
    } 
    catch (const std::exception& e) {
        // 값을 찾지 못한 경우의 예외 처리
        std::cout << "결과: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // === 1. std::vector 테스트 ===
    std::cout << "##### std::vector 테스트 #####" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    
    // 값이 있는 경우
    runTest(vec, 30, "vector - 값이 있는 경우");
    
    // 값이 없는 경우
    runTest(vec, 100, "vector - 값이 없는 경우");
    
    // === 2. std::list 테스트 ===
    std::cout << "##### std::list 테스트 #####" << std::endl;
    
    std::list<int> lst;
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);
    
    // 값이 있는 경우
    runTest(lst, 35, "list - 값이 있는 경우");
    
    // 값이 없는 경우
    runTest(lst, 55, "list - 값이 없는 경우");
    
    // === 3. std::deque 테스트 ===
    std::cout << "##### std::deque 테스트 #####" << std::endl;
    
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_back(15);
    deq.push_back(25);
    
    // 값이 있는 경우
    runTest(deq, 15, "deque - 값이 있는 경우");
    
    // 값이 없는 경우
    runTest(deq, 30, "deque - 값이 없는 경우");
    
    // === 4. 엣지 케이스: 빈 컨테이너 ===
    std::cout << "##### 엣지 케이스: 빈 컨테이너 #####" << std::endl;
    
    std::vector<int> emptyVec;
    runTest(emptyVec, 10, "빈 벡터");
    
    // === 5. 추가 테스트: 중복된 값 ===
    std::cout << "##### 추가 테스트: 중복된 값 #####" << std::endl;
    
    std::vector<int> dupVec;
    dupVec.push_back(10);
    dupVec.push_back(20);
    dupVec.push_back(10); // 중복된 값
    dupVec.push_back(30);
    
    // 중복된 값을 찾을 때 (첫 번째 발생 위치를 반환해야 함)
    runTest(dupVec, 10, "중복 값이 있는 벡터");
    
    return 0;
}