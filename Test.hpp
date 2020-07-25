#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>

template<typename T, typename U>
inline bool __assertEqual (T a, U b)
{
  return a == b;
}

template<>
inline bool __assertEqual (const std::string& str1, const char* str2)
{
  return str1.compare(str2) == 0;
}

#define TESTABLE friend int main();

#define LOG(BLOCK) std::cout << BLOCK << std::endl;

#define TEST(NAME, BLOCK) \
  { \
    int __errorsCurrentTest = 0; \
    std::cout << NAME; \
    BLOCK; \
    if (__errorsCurrentTest == 0) \
      std::cout << "......SUCCESS"; \
    std::cout << std::endl; \
  }

#define ASSERT_EQ(A, B) \
  if (!__assertEqual(A, B)) { \
    std::cout << "\n    "; \
    std::cout << "Assertion failed: ASSERT_EQ("; \
    std::cout << #A; \
    std::cout << ", "; \
    std::cout << #B; \
    std::cout << ")"; \
    __errorsCurrentTest++; \
  }


#endif