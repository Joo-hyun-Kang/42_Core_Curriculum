#include <iostream>

int main(void)
{
    /*
        참조
        1. 별칭이다
        2. NULL이 될 수 없음
        3. 초기화 중에 선언되어야 함
        4. 참조하는 대상을 바꿀 수 없음
    */

    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable : " << &str << std::endl;
    std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;

    std::cout << "The value of the string variable          : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;

    return 0;
}