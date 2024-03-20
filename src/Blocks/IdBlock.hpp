#ifndef IdBlock_HPP
#define IdBlock_HPP

#include <fstream>
#include <string>
#include <cstdint> 

using namespace std;

class IdBlock{
    private:
        struct IdStruct
        {
            string blockTypeId;            
            string idFile;
            string idVers;
            string idProg;
            uint32_t idReserved1;               
            uint16_t idVer;                     
            string idReserved2;
            uint16_t idUnfinFlags;              
            uint16_t idCustomUnfinFlags;        
        };
    public:
        void GetIdentificationInfo(ifstream &mdfFile);
};

extern IdBlock idBlock;
#endif