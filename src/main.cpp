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
    f.log<<"------------------------------------------1号报文---------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos1);
    f.log<<"------------------------------------------2号报文----------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos5);
    f.log<<"------------------------------------------21号报文--------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos21);
    f.log<<"------------------------------------------24A号报文--------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos24A);
    f.log<<"------------------------------------------24B号报文--------------------------------------------------------------"<<endl;
    f.logWrite(info.Infos24B);
    file.close(); // 关闭文件
    return 0;
}