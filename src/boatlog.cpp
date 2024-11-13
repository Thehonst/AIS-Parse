#include <iostream>
#include<map>
#include "boatlog.h"
BoatLog::BoatLog(){}
BoatLog::~BoatLog(){}
std::map<uint32_t,Numb> BoatLog::repeate(std::map<uint32_t,Numb> &Infos,
                                        uint32_t MMSI_,uint32_t value,uint32_t Time) {
    
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
        Infos[MMSI_].freq.push_back(Time-Infos[MMSI_].lastTime);
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
    std::cout<<"MMSI: "<<" "<<Time<<" "<<Infos[MMSI_].lastTime<<std::endl;
    Infos[MMSI_].lastTime=Time;
    return Infos;
}



