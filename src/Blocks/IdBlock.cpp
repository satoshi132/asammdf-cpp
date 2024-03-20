#include "IdBlock.hpp"
#include <iostream>

IdBlock idBlock;

/**
 * This function takes refernce of mdfFile as stream and 
 * prints the identification information for the given
 * mf4 file
 * @param mdfFile(ifstream) -- mdf File in stream
 * @return void
*/
void IdBlock::GetIdentificationInfo(ifstream &mdfFile)
{
    IdStruct *idStruct = new IdStruct;
    // First 64 Bytes are for idStruct

    char buffer[30];
    mdfFile.read(buffer, 8);

    idStruct->idFile.assign(buffer, 8);

    mdfFile.read(buffer, 8);
    idStruct->idVers.assign(buffer, 8);

    mdfFile.read(buffer, 8);
    idStruct->idProg.assign(buffer, 8);

    mdfFile.read(reinterpret_cast<char *>(&idStruct->idReserved1), 4);

    idStruct->blockTypeId = "ID";

    mdfFile.read(reinterpret_cast<char *>(&idStruct->idVer), 2);

    mdfFile.read(buffer, 30);
    idStruct->idReserved2.assign(buffer, 30);

    mdfFile.read(reinterpret_cast<char *>(&idStruct->idUnfinFlags), 2);

    mdfFile.read(reinterpret_cast<char *>(&idStruct->idCustomUnfinFlags), 2);

    std::streampos position = mdfFile.tellg();
    std::cout << "Current position in the file: " << position << std::endl;

    // Print the values
    std::cout << "Block Type ID: " << idStruct->blockTypeId << std::endl;
    std::cout << "ID File: " << idStruct->idFile << std::endl;
    std::cout << "ID Version: " << idStruct->idVers << std::endl;
    std::cout << "ID Program: " << idStruct->idProg << std::endl;
    std::cout << "ID Reserved 1: " << idStruct->idReserved1 << std::endl;
    std::cout << "ID Version Number: " << idStruct->idVer << std::endl;
    std::cout << "ID Reserved 2: " << idStruct->idReserved2 << std::endl;
}
