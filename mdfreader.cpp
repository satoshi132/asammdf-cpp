#include <iostream>
#include <fstream>

int main()
{
    std::string inputFile = "ASAP2_Demo_V171.mf4";
    std::ifstream mdfFile(inputFile);
    if(mdfFile.is_open())
    {
        std::cout<< "File Opened Successfully"<< std::endl;
        mdfFile.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl ;
    }  
    return  0;
} 