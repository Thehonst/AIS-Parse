#include "type_haddle.h"
#include<bitset>
#include<string>
using namespace std;
MsgHaddle::MsgHaddle() {}
MsgHaddle::~MsgHaddle() {}
//字段解析
uint32_t field_parse(string str,int a,int b)
{
    string field (str,a,b);
    bitset<32> binaryStr(field);
    return binaryStr.to_ulong();
}
//经纬度处理函数
float MsgHaddle::lat_lon_convert(u_int32_t lat_lon_value)
{
    return lat_lon_value/600000.0;
}
//消息1解析方法
MsgHaddle MsgHaddle::haddle1(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    NaviStatus=field_parse(data,38,4);
    ROT=field_parse(data,42,8);
    SOG=field_parse(data,50,10)/10.0;
    PosAcc= field_parse(data,60,1);
    lon=lat_lon_convert(field_parse(data,61,28));
    lat=lat_lon_convert(field_parse(data,89,27));
    COG=field_parse(data,116,12)/10.0;
    TrueHeading=field_parse(data,128,9);
    TimeStamp=field_parse(data,137,6);
    return *this;
}
//消息5解析方法
MsgHaddle MsgHaddle::haddle5(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    version=field_parse(data,38,2);
    IMO=field_parse(data,40,30);
    CallSign=field_parse(data,70,42);
    Name=field_parse(data,112,120);
    ShipType=field_parse(data,232,8);
    PosRef=field_parse(data,240,30);
    ElecLocalType=field_parse(data,270,4);
    arriTime=field_parse(data,274,20);
    draft=field_parse(data,294,8);
    dest=field_parse(data,302,120);
    Terminal=field_parse(data,422,1);
    return *this;

}
//消息18解析方法
MsgHaddle MsgHaddle::haddle18(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    Reserve=field_parse(data,38,8);
    SOG=field_parse(data,46,10)/10.0;
    PosAcc=field_parse(data,56,1);
    lon=lat_lon_convert(field_parse(data,57,28));
    lat=lat_lon_convert(field_parse(data,85,27));
    COG=field_parse(data,112,12)/10.0;
    TrueHeading=field_parse(data,124,9);
    TimeStamp=field_parse(data,133,6);
    Reserve2=field_parse(data,139,2);
    B_Flag=field_parse(data,141,1);
    B_Screen=field_parse(data,142,1);
    DSC=field_parse(data,143,1);
    Band=field_parse(data,144,1);
    B_22=field_parse(data,145,1);
    Mode=field_parse(data,146,1);
    RAIM=field_parse(data,147,1);
    CommState_=field_parse(data,148,1);
    CommState=field_parse(data,149,19);
    return *this;
}
//消息19解析方法
MsgHaddle MsgHaddle::haddle19(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    Reserve=field_parse(data,38,8);
    SOG=field_parse(data,46,10)/10.0;
    PosAcc=field_parse(data,56,1);
    lon=lat_lon_convert(field_parse(data,57,28));
    lat=lat_lon_convert(field_parse(data,85,27));
    COG=field_parse(data,112,12)/10.0;
    TrueHeading=field_parse(data,124,9);
    TimeStamp=field_parse(data,133,6);
    Reserve2=field_parse(data,139,4);
    Name=field_parse(data,143,120);
    ShipType=field_parse(data,263,8);
    PosRef=field_parse(data,271,30);
    ElecLocalType=field_parse(data,301,4);
    RAIM=field_parse(data,305,1);
    DTE=field_parse(data,306,1);
    AsigMod=field_parse(data,307,1);
    Reserve3=field_parse(data,308,4);
    return *this;
}
//消息21解析方法
MsgHaddle MsgHaddle::haddle21(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    AidNavType=field_parse(data,38,5);
    AidNavName=field_parse(data,43,120);
    PosAcc=field_parse(data,163,1);
    lon=lat_lon_convert(field_parse(data,164,28));
    lat=lat_lon_convert(field_parse(data,192,27));
    size_posRef=field_parse(data,219,30);
    ElecLocalType=field_parse(data,249,4);
    TimeStamp=field_parse(data,253,6);
    BiasPos=field_parse(data,259,1);
    AtoN=field_parse(data,260,8);
    RAIM=field_parse(data,268,1);
    VirAtoN=field_parse(data,269,1);
    AssignedMode=field_parse(data,270,1);

    return *this;
}

//消息24A解析方法
MsgHaddle MsgHaddle::haddle24A(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    PartNum=field_parse(data,38,2);
    ShipName=field_parse(data,40,120);

    return *this;
}
//消息24B解析方法
MsgHaddle MsgHaddle::haddle24B(string data)
{
    Type=field_parse(data,0,6);
    TransCount=field_parse(data,6,2);
    MMSI=field_parse(data,8,30);
    PartNum=field_parse(data,38,2);
    ShipType=field_parse(data,40,8);
    VendorID=field_parse(data,48,42);
    CallSign=field_parse(data,90,42);
    size_posRef=field_parse(data,132,30);

    return *this;
}
