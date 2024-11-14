#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include<vector>
#include<sstream>
#include<ctime>
#include<map>
#include"split.h"
#include"Time.h"
#include "type_haddle.h"
#include"file.h"
#include"AISPare.h"
#include"boatlog.h"
#include"log_haddle.h"
using namespace std;
int main()
{   
    std::ifstream file("/home/mzf/data/20240521_v2.txt"); // 打开文件
    File f;
    LogHaddle info;
    f.createFile();
    f.openFile();
    f.createHeader();
    std::string line;
    BoatLog boatlog;
    int count=0;
    while(getline(file,line))
    {
        std::vector<std::string> new_line1={};
        vector<std::string> line_split{};
        split(line,line_split,',');

        char* timeStr = Time_(static_cast<time_t>(std::stoi(line_split[0])));
        std::string str = line_split[6];
        if(str.length()<16)
        {
            continue;
        }
        string data_bin;
        ais_decode(str,data_bin);
        auto num=field_parse(data_bin,0,6);
        
        count++;
        cout<<count<<"  "<<line_split[6]<<endl;
        //1号报文
        if(num==1||num==2||num==3)
        {
            if (f.t1.MMSI==0)
            {
                continue;/* code */
            }
            //cout<<timeStr<<endl;
            f.contentWrite(timeStr,line_split,data_bin, new_line1,123);
            boatlog.repeate(info.Infos1,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
        }
        //5号报文
        if(num==5)
        {
            if(data_bin.length()<400)
            {
                continue;
            }
            f.contentWrite(timeStr,line_split,data_bin, new_line1,5);   
            boatlog.repeate(info.Infos5,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
        }
        //18号报文
        if(num==18)
        {
            if(data_bin.length()<168)
            {
                continue;
            }
            f.contentWrite(timeStr,line_split,data_bin, new_line1,18);   
            boatlog.repeate(info.Infos18,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
        }
        //19号报文
        if(num==19)
        {
            if(data_bin.length()<112)
            {
                continue;
            }
            f.contentWrite(timeStr,line_split,data_bin, new_line1,19);   
            boatlog.repeate(info.Infos19,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
        }
        //21号报文
        if(num==21)
        {
            f.contentWrite(timeStr,line_split,data_bin, new_line1,21);   
            boatlog.repeate(info.Infos21,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
        }
        //24号报文
        if(num==24)
        {
            auto partnum=field_parse(data_bin,38,2);
            //24A号报文
            if(partnum==0)
            {
                f.contentWrite(timeStr,line_split,data_bin, new_line1,240); 
                boatlog.repeate(info.Infos24A,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
            }
            //24B号报文
            if(partnum==1)
            {
               f.contentWrite(timeStr,line_split,data_bin, new_line1,241); 
               boatlog.repeate(info.Infos24B,field_parse(data_bin,8,30),field_parse(data_bin,6,2),std::stoi(line_split[0]));
            }
        }
        delete[] timeStr; // 释放动态分配的内存
    }
    f.log<<"消息1,2,3,5由A类船只发出,消息18、19由B类船只发送,消息21由AtoN(助航设备：如灯塔、浮标、导航标志)发送,24A部分由AIS台发送(船只、基站、助航设备),24B部分由A类船只发送消息5的目的地通常是一个MMSI(海上移动业务标识)号码,"<<endl;
    f.log<<"这是一个由30位数字组成的唯一标识符,用于识别船舶、基站或其他海上实体。MMSI号码的格式遵循国际电信联盟(ITU)的规则,其中前3位是国家代码,后27位是船舶或其他实体的唯一标识。电信联盟(ITU)的规则,其中前3位是国家代码,后27位是船"<<endl;
    f.log<<"舶或其他实体的唯一标识。因此,消息5的目的地最终是一个由30位数字组成的MMSI号码,而不是一串数字。这个MMSI号码用于在AIS消息中标识特定的船舶或基站,确保消息能够被正确地发送到预定的目的地。"<<endl;
    f.log<<"用True False 标识是否满足标称报告间隔"<<endl;
    f.log<<"------------------------------------------1号报文-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos1, Numb::AISType::A);
    f.log<<"------------------------------------------2号报文------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos5,Numb::AISType::A);
    f.log<<"------------------------------------------18号报文------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos18,Numb::AISType::B);
    f.log<<"------------------------------------------19号报文-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos19,Numb::AISType::B);
    f.log<<"------------------------------------------21号报文-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos21,Numb::AISType::AtoN);
    f.log<<"------------------------------------------24A号报文-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos24A,Numb::AISType::AIST);
    f.log<<"------------------------------------------24B号报文-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos24B,Numb::AISType::B);
    file.close(); // 关闭文件
    return 0;
}