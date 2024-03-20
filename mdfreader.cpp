#include <iostream>
#include <fstream>
#include "src/Blocks/IdBlock.hpp"

int main()
{
    string inputFile = "ASAP2_Demo_V171.mf4";
    ifstream mdfFile(inputFile);
    if(mdfFile.is_open())
    {
        cout<< "File Opened Successfully"<< endl;
        //Extracting Identification block info from mdf file
        idBlock.GetIdentificationInfo(mdfFile);
        mdfFile.close();
    }
    else
    {
        cerr << "Unable to open file" << endl ;
    }  
    return  0;
} 