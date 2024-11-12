#include<map>
#include "boatlog.h"
#include <iostream>
BoatLog::BoatLog(){}
BoatLog::~BoatLog(){}
std::map<uint32_t,Numb> BoatLog::repeate(std::map<uint32_t,Numb> &Infos,
                                        uint32_t MMSI_,uint32_t value,uint32_t Time) {
    uint32_t last_Time;
    if (Infos.find(MMSI_) != Infos.end()) 
    {
        if (value==0)
        {
            //std::cout << "MMSI: " << MMSI_ << " is already in the map" << std::endl;
            ++Infos[MMSI_].count;
           
            Infos[MMSI_].Rate=Infos[MMSI_].transmit/Infos[MMSI_].count;
        }
        else if (value==1) 
        {
            ++Infos[MMSI_].count;
            ++Infos[MMSI_].transmit;
            Infos[MMSI_].Rate=Infos[MMSI_].transmit/Infos[MMSI_].count;
        }
        Infos[MMSI_].freq.push_back(Time-last_Time);
    }
    else
        {
            Numb numb;
            if (value==0)
            {
                numb.count=1;
                numb.transmit=0;
                numb.Rate=0;
            }
            else if (value==2)
            {
                numb.count=1;
                numb.transmit=1;
                numb.Rate=1;
            }
            numb.freq.push_back(0);
            Infos.insert(std::make_pair(MMSI_,numb));
            
        }
        last_Time=Time;
    
    return Infos;
}



