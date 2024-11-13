#ifndef TYPE_HADDLE_H
#define TYPE_HADDLE_H
// this is a haddler for Mesg123
#include <iostream>
#include <string>
uint32_t field_parse(std::string str,int a,int b);

class MsgHaddle
{
public:
    MsgHaddle();
    ~MsgHaddle();
    MsgHaddle haddle1(std::string data);
    MsgHaddle haddle5(std::string data);
    MsgHaddle haddle18(std::string data);
    MsgHaddle haddle19(std::string data);
    MsgHaddle haddle21(std::string data);
    MsgHaddle haddle24A(std::string data);
    MsgHaddle haddle24B(std::string data);
    float lat_lon_convert(u_int32_t lat_lon_value);
    
    uint32_t Type;
    uint32_t TransCount;
    uint32_t MMSI;

    //1，2，3号报文
    uint32_t NaviStatus;
    uint32_t ROT; // Rate of Turn
    float SOG; // Speed Over Ground
    uint32_t PosAcc;  // Position Accuracy
    float lon; //经度
    float lat; //纬度
    float COG; // Course Over Ground
    uint32_t TrueHeading;
    uint32_t TimeStamp;
    //std::string Admin;

    //5号报文
    uint32_t version;      //AIS版本号
    uint32_t IMO;          //IMO号码
    uint32_t CallSign;  //呼叫号
    uint32_t Name;
    uint32_t ShipType;     //船舶和货物类型   
    uint32_t PosRef;        //位置参考
    uint32_t ElecLocalType; //电子定位装置类型
    uint32_t arriTime;      //到达时间
    uint32_t draft;     //吃水
    uint32_t dest;      //目的地
    uint32_t Terminal;  //终端

    //18号报文
    uint32_t Reserve; //备用
    //uint32_t SOG; //
    //uint32_t PosAcc; //Position Accuracy
    //float lon; //经度
    //float lat; //纬度
    //uint32_t COG; //Course Over Ground
    //uint32_t TrueHeading;
    //uint32_t TimeStamp;
    uint32_t Reserve2; //备用2
    uint32_t B_Flag; //0 = B类SOTDMA装置 1 = B类 “CS”装置
    uint32_t B_Screen; //显示器标志
    uint32_t DSC;  //B类DSC
    uint32_t Band; //B类带宽
    uint32_t B_22;
    uint32_t Mode; //B类模式
    //uint32_t RAIM; //B类RAIM
    uint32_t CommState_; //通信状态标志
    uint32_t CommState; //通信状态

    //19号报文
    //uint32_t Reserve; //备用
    //uint32_t SOG; //Speed Over Ground
    //uint32_t PosAcc; //Position Accuracy
    //float lon; //经度
    //float lat; //纬度
    //uint32_t COG; //Course Over Ground
    //uint32_t TrueHeading;
    //uint32_t TimeStamp;
    //uint32_t Reserve2; //备用2
    // uint32_t Name;
    // uint32_t ShipType;     //船舶和货物类型   
    // uint32_t PosRef;        //位置参考
    // uint32_t ElecLocalType; //电子定位装置类型
    //uint32_t RAIM;  //TRAIM
    uint32_t DTE; //数据终端就绪
    uint32_t AsigMod; //分配模式
    uint32_t Reserve3; //备用3

    //21号报文
    uint32_t AidNavType;      //助航设备类型
    uint32_t AidNavName;      //助航设备名称
    //uint32_t PosAcc;  // Position Accuracy
    //float lon; //经度
    //float lat; //纬度
    uint32_t size_posRef;     //尺寸/ 位置参考点 
    //uint32_t ElecLocalType; //电子定位装置类型
    //uint32_t TimeStamp;   //时间戳
    uint32_t BiasPos;     //Bias position indicator
    uint32_t AtoN;      //AtoN状态
    uint32_t RAIM;  //TRAIM
    uint32_t VirAtoN; //虚拟AtoN标志
    uint32_t AssignedMode; //分配模式
    
    //24号报文A
    uint32_t PartNum;
    uint32_t ShipName;

    //24号报文B
    //uint32_t PartNum;
    //uint32_t ShipType;
    uint32_t VendorID; //制造商ID
    //uint32_t CallSign;  //呼叫号
    //uint32_t size_posRef; //尺寸/ 位置参考点 

};

#endif // TYPE_HADDLE_H