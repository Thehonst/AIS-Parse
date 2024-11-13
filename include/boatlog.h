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
    enum AISType { A,AtoN,Station,AIST,B};//"A", "AtoN","基站","AIS台","B"
    std::map<AISType,std::string> AISTypeToString={
        {A,"A"},
        {AtoN,"AtoN"},
        {Station,"基站"},
        {AIST,"AIS台"},
        {B,"B"}
    };
    std::vector<uint32_t> freq;
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