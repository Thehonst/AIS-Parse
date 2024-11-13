#ifndef BOATLOG_H
#define BOATLOG_H
#include<map>
#include<vector>
#include<string>
struct Numb
{
    int count=0;
    int transmit;
    float Rate;
    uint32_t lastTime=0;
    
    std::vector<std::string> freq;
};
class BoatLog
{
public:
    BoatLog();
    ~BoatLog();
    std::map<uint32_t,Numb> repeate(std::map<uint32_t,Numb> &Infos,
                                     uint32_t MMSI,uint32_t TransCount,uint32_t Time);
};


#endif // BOATMSGCAL_H