#include <iostream>
#include <string>
#include <string.h>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        
        return 1;
    }

    std::string str;

    for (int i = 1; i < argc; i++)
    {        
        str.append(argv[i]);
        str.append(" ");
    }

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    std::cout << std::uppercase << str << std::endl;

    return 1;
}