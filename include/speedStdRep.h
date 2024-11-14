#ifndef SPEEDSTDREP_H
#define SPEEDSTDREP_H
#include <string>
#include"boatlog.h"
std::string speedStdRep(uint32_t Time_period,float SOG, uint32_t NaviStatus);
std::string speedStdRep(uint32_t Time_period,float SOG,Numb::AISType AIS_Type);
#endif