#include"proc.h"

int main()
{
    CPU mass;
    /*std::string str1("mov %reA %B"), str2("mov %A $213");

    for(int i = 0; i < mass.size_arr_; i++)
    {
        std::cout << mass.arr_command_[i]->mask_ << "\n";
        std::cout << mass.arr_command_[i]->mask_cmp(str1) << " " << mass.arr_command_[i]->mask_cmp(str2) << std::endl;
    }
    */
    mass.compile("square.dat", "square.o");
    mass.run("square.o");

    return 0;
}
