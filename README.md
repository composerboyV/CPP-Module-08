# 📚 CPP Module 08 - STL Containers, Iterators, Algorithms

## 🎯 Overview

이 모듈은 C++ STL(Standard Template Library)의 핵심 구성요소인 **컨테이너**, **반복자**, **알고리즘**을 깊이 있게 학습하는 과정입니다.

---

## 📝 Exercise 00: Easy find

### 🎓 학습 목표

- **템플릿 함수** 작성법 이해
- STL **알고리즘** 활용 (`std::find`)
- 다양한 **컨테이너**와의 호환성
- **예외 처리** 패턴

### 💡 문제 해결 과정

### 1. **템플릿 설계**

```cpp

cpp
template <typename T>
typename T::iterator easyfind(T& container, int value);

```

- 모든 STL 시퀀스 컨테이너와 호환되도록 템플릿 사용
- `typename` 키워드로 의존적 타입명 명시

### 2. **STL 알고리즘 활용**

```cpp

cpp
typename T::iterator it = std::find(container.begin(), container.end(), value);

```

- 바퀴를 재발명하지 않고 표준 라이브러리 활용
- 코드의 신뢰성과 효율성 보장

### 3. **예외 처리**

```cpp

cpp
if (it == container.end()) {
    throw std::runtime_error("Value not found");
}

```

- 값을 찾지 못한 경우 명확한 예외 발생
- STL의 일반적인 패턴 따르기

### 🔍 핵심 개념

- **Iterator Pattern**: 컨테이너의 내부 구조와 독립적으로 요소 순회
- **Generic Programming**: 타입에 독립적인 코드 작성
- **RAII**: 예외 안전성 보장

---

## 📊 Exercise 01: Span

### 🎓 학습 목표

- **컨테이너 설계** 및 구현
- STL **알고리즘** 심화 활용
- **반복자 범위** 처리
- 효율적인 **알고리즘 구현**

### 💡 문제 해결 과정

### 1. **데이터 구조 선택**

```cpp

cpp
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

```

- `std::vector` 선택: 동적 크기 조절, 랜덤 액세스, 정렬 효율성

### 2. **최단/최장 거리 알고리즘**

```cpp

cpp
int shortestSpan() {
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i-1]);
    }
    return minSpan;
}


```

- 템플릿으로 다양한 반복자 타입 지원
- STL의 일반적인 인터페이스 패턴 구현

### 🔍 핵심 개념

- **알고리즘 최적화**: 정렬을 통한 효율적인 탐색
- **예외 안전성**: 강력한 예외 보장
- **STL 호환성**: 표준 라이브러리와 일관된 인터페이스

---

## 🔄 Exercise 02: Mutated abomination

### 🎓 학습 목표

- **상속**을 통한 기능 확장
- **어댑터 패턴** 이해
- STL 컨테이너의 **내부 구조** 파악
- **반복자 구현**

### 💡 문제 해결 과정

### 1. **std::stack 분석**

```cpp

cpp
template <typename T, typename Container = std::deque<T>>
class stack {
protected:
    Container c;// 내부 컨테이너
};

```

- `std::stack`은 내부적으로 다른 컨테이너를 감싸는 어댑터
- `protected` 멤버 `c`를 통해 내부 컨테이너 접근 가능

### 2. **상속을 통한 확장**

```cpp

cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
};

```

- public 상속으로 모든 stack 기능 유지
- 타입 별칭으로 복잡한 타입명 단순화

### 3. **반복자 인터페이스 추가**

```cpp

cpp
iterator begin() { return this->c.begin(); }
iterator end() { return this->c.end(); }
const_iterator begin() const { return this->c.begin(); }
const_iterator end() const { return this->c.end(); }

```

- 내부 컨테이너의 반복자 직접 노출
- const 정확성 보장

### 🔍 핵심 개념

- **어댑터 패턴**: 기존 인터페이스를 새로운 인터페이스로 변환
- **템플릿 특수화**: 컴파일 타임 다형성
- **const 정확성**: 불변 객체에 대한 안전한 접근

---

## 🌟 주요 학습 포인트

### 1. **STL의 3대 구성요소**

- **컨테이너**: 데이터를 저장하는 자료구조
- **반복자**: 컨테이너의 요소를 순회하는 일반화된 포인터
- **알고리즘**: 반복자를 통해 컨테이너를 조작하는 함수

### 2. **템플릿 프로그래밍**

- 타입에 독립적인 코드 작성
- 컴파일 타임 다형성
- 코드 재사용성 극대화

### 3. **예외 안전성**

- 강력한 예외 보장 (Strong Exception Guarantee)
- RAII 원칙 적용
- 명확한 에러 처리

### 4. **STL 설계 철학**

- 효율성과 일반성의 균형
- 일관된 인터페이스
- 확장 가능한 설계

## 💪 결론

이 모듈을 통해 C++ STL의 핵심 개념을 실습하며, 효율적이고 재사용 가능한 코드를 작성하는 방법을 학습했습니다. 특히 템플릿과 STL을 활용한 제네릭 프로그래밍의 강력함을 체험할 수 있었습니다.
