#include <iostream>

void swap0(int &a, int &b)
{ //with a temp num
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap1(int &a, int &b)
{ //with addition
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap2(int &a, int &b)
{ //with subtraction
    a = a - b;
    b = a + b;
    a = b - a;
}

void swap3(int &a, int &b)
{ //with multiplication
    a = a * b;
    b = a / b;
    a = a / b;
}

void swap4(int &a, int &b)
{ //with division
    a = a / b;
    b = a * b;
    a = b / a;
}

void swap5(int &a, int &b)
{ //with logical operator
    int temp = (a & b) ^ (a | b);
    a = temp ^ a;
    b = temp ^ b;
}

void swap6(int &a, int &b)
{ //with XOR operator
    a ^= b;
    b ^= a;
    a ^= b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m = 2, n = 1;
    std::cout << m << n << std::endl;
    swap0(m, n);
    std::cout << m << n << std::endl;
    swap1(m, n);
    std::cout << m << n << std::endl;
    swap2(m, n);
    std::cout << m << n << std::endl;
    swap3(m, n);
    std::cout << m << n << std::endl;
    swap4(m, n);
    std::cout << m << n << std::endl;
    swap5(m, n);
    std::cout << m << n << std::endl;
    swap6(m, n);
    std::cout << m << n << std::endl;
    return 0;
}