#include "Data.hpp"

int main()
{
    struct Data data;
    data.value = "Cast Test";

    std::cout << "Serialize!" << std::endl;
    uintptr_t raw = serialize(&data);

    std::cout << "deserialize!" << std::endl;
    Data *data_copy = deserialize(raw);

    std::cout << "origin data address : " << &data << std::endl;
    std::cout << "converted data address : " << data_copy << std::endl;

    if (&data == data_copy)
    {
        std::cout << "Same" << std::endl;
    }
    std::cout << data_copy->value << std::endl;

    return 0;
}