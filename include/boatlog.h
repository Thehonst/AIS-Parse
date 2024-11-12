#ifndef BOATLOG_H
#define BOATLOG_H
#include<map>
#include<vector>
struct Numb
{
    int count;
    int transmit;
    float Rate;
    
    std::vector<int> freq;
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