#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    const int VAILD_INPUT = 4;
    if (argc != VAILD_INPUT)
    {
        std::cout << "InVaild Input Please input filename, s1, s2" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string src = argv[2];
    std::string dst = argv[3];

    if (fileName.empty() || src.empty() || dst.empty())
    {
        std::cout << "Input is empty Please check again" << std::endl;
        return 1;
    }

    std::ifstream fin;
    std::ofstream fout;

    fin.open(fileName);
    if (fin.is_open() == false)
    {
        std::cout << "Can't open file Please check your input" << std::endl;
        return 1;
    }

    fout.open(fileName + ".replace");
    if (fout.is_open() == false)
    {
        std::cout << "Can't open replace file Please check your input" << std::endl;
        return 1;
    }

    std::string line;
    while (true)
    {
        std::getline(fin, line);
        
        size_t position = 0;
        for (size_t i = 0; i < line.length(); i++)
        {
            position = line.find(src, i);
            if (position != std::string::npos)
            {
                line.erase(position, src.length());
                line.insert(position, dst);
            }
        }

        fout << line;
        if (fin.eof())
        {
            break;
        }
        
        fout << std::endl;;
    }

    fin.close();
    fout.close();

    return (0);
}
