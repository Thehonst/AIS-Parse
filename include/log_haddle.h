#ifndef LOG_HADDE_H
#define LOG_HADDE_H
#include<map>
#include"boatlog.h"
class LogHaddle
{
public:
    LogHaddle();
    ~LogHaddle();
    
    std::map<uint32_t,Numb> Infos1;
    std::map<uint32_t,Numb> Infos5;
    std::map<uint32_t,Numb> Infos21;
    std::map<uint32_t,Numb> Infos24A;
    std::map<uint32_t,Numb> Infos24B;

};

#endif