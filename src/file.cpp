#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<memory>
#include "file.h"
#include"split.h"
#include"boatlog.h"
using namespace std;
File::File() {}
File::~File() 
{
  outfile1.close();
  outfile5.close();
  outfile21.close();
  outfile24A.close();
  outfile24B.close();

  log.close();
}
void File::createFile()
{
    headers1 = {"     Time","MsgNum","MsgSequence","channel", 
      "MsgType","MMSI编号", "TransTime", "NaviStatus","ROT","SOG","PosAcc","lon",
      "lat","COG","TrueHeading","TimeStamp"};
    headers5 = {"     Time","MsgNum","MsgSequence","channel", 
      "MsgType","MMSI编号", "TransTime","version", "IMO","CallSign",
      "Name","ShipType","PosRef","ElecLocalType","arriTime",
      "draft","dest","Terminal"
      };
    headers21 = {"     Time","MsgNum","MsgSequence","channel", 
      "MsgType","MMSI编号", "TransTime", "AidNavType","AidNavName",
      "PosAcc","lon","lat","size_posRef","ElecLocalType","TimeStamp",
      "BiasPos","AtoN","TRAIM","VirAtoN","AssignedMode"};
    headers24A = {"     Time","MsgNum","MsgSequence","channel", 
      "MsgType","MMSI编号", "TransTime","PartNum","ShipName"};
    headers24B = {"     Time","MsgNum","MsgSequence","channel", 
      "MsgType","MMSI编号", "TransTime","PartNum","ShipType","VendorID",
      "CallSign","size_posRef" };

    outfile1.open("/home/mzf/data/消息1.txt");
    outfile5.open("/home/mzf/data/消息5.txt");
    outfile21.open("/home/mzf/data/消息21.txt");
    outfile24A.open("/home/mzf/data/消息24A.txt");
    outfile24B.open("/home/mzf/data/消息24B.txt");


    log.open("/home/mzf/data/log.txt");
}
void File::openFile()
{
  std::ofstream& outfile1 = this->outfile1;
  std::ofstream& outfile5 = this->outfile5;
  std::ofstream& outfile21 = this->outfile21;
  std::ofstream& outfile24A = this->outfile24A;
  std::ofstream& outfile24B = this->outfile24B;
  std::ofstream& log = this->log;
}
void File::createHeader()
{
  for (const auto& header : headers1) 
  {
      outfile1 << header << "\t"; // 使用制表符作为列分隔符
  }
  outfile1 << std::endl;
  for (const auto& header : headers5)
  {
      outfile5 << header << "\t"; // 使用制表符作为列分隔符
  }
  outfile5 << std::endl;
  for (const auto& header : headers21)
  {
      outfile21 << header << "\t"; // 使用制表符作为列分隔符
  }
  outfile21 << std::endl;
  for (const auto& header : headers24A)
  {
      outfile24A << header << "\t"; // 使用制表符作为列分隔符
  }
  outfile24A << std::endl;
  for (const auto& header : headers24B)
  {
      outfile24B << header << "\t"; // 使用制表符作为列分隔符
  }
  outfile24B << std::endl;
  
}
void File::contentWrite(char* timeStr,std::vector<std::string> &line_split,string data_bin,
                        std::vector<std::string> &new_line1,int flag)
{
  MsgHaddle Msg;

  if (flag == 123)
  {
    
    MsgHaddle t1=Msg.haddle1(data_bin);
    new_line1.assign({timeStr, line_split[2], line_split[3], line_split[5], 
            to_string(t1.Type), to_string(t1.MMSI),to_string(t1.TransCount),
            to_string(t1.NaviStatus),to_string(t1.ROT),to_string(t1.SOG),to_string(t1.PosAcc),
            to_string(t1.lon),to_string(t1.lat),to_string(t1.COG),to_string(t1.TrueHeading),
            to_string(t1.TimeStamp)});
    for (size_t i = 0; i < new_line1.size(); ++i) 
    {
        outfile1 << new_line1[i] << "\t"; // 使用制表符作为列分隔符
    }
    outfile1 << std::endl; // 新行
  }

  if (flag == 5)
  {
    MsgHaddle t5=Msg.haddle5(data_bin);
    new_line1.assign({timeStr, line_split[2], line_split[3], line_split[5], 
            to_string(t5.Type), to_string(t5.MMSI),to_string(t5.TransCount),
            to_string(t5.version),to_string(t5.IMO),to_string(t5.CallSign),
            to_string(t5.Name),
            to_string(t5.ShipType),to_string(t5.PosRef),to_string(t5.ElecLocalType),
            to_string(t5.arriTime),to_string(t5.draft),
            //to_string(t5.dest),
            //to_string(t5.Terminal)
            });
    for (size_t i = 0; i < new_line1.size(); ++i) 
    {
        outfile5 << new_line1[i] << "\t"; // 使用制表符作为列分隔符
    }
    outfile5 << std::endl; // 新行
  }
  if (flag == 21)
  {
    MsgHaddle t21=Msg.haddle21(data_bin);
    new_line1.assign({timeStr, line_split[2], line_split[3], line_split[5], 
            to_string(t21.Type), to_string(t21.MMSI),to_string(t21.TransCount),
            to_string(t21.AidNavType),to_string(t21.AidNavName),to_string(t21.PosAcc),
            to_string(t21.lon),to_string(t21.lat),to_string(t21.size_posRef),
            to_string(t21.ElecLocalType),
            to_string(t21.TimeStamp),to_string(t21.BiasPos),to_string(t21.AtoN),
            to_string(t21.RAIM),to_string(t21.VirAtoN),to_string(t21.AssignedMode)});
    for (size_t i = 0; i < new_line1.size(); ++i) 
    {
        outfile21 << new_line1[i] << "\t"; // 使用制表符作为列分隔符
    }
    outfile21 << std::endl; // 新行
  }

  if (flag == 240)
  {
    MsgHaddle t24=Msg.haddle24A(data_bin);

    new_line1.assign({timeStr, line_split[2], line_split[3], line_split[5], 
        to_string(t24.Type), to_string(t24.MMSI),to_string(t24.TransCount),
        to_string(t24.PartNum),to_string(t24.ShipName)});
    for (size_t i = 0; i < new_line1.size(); ++i) 
    {
        outfile24A << new_line1[i] << "\t"; // 使用制表符作为列分隔符
    }
    outfile24A << std::endl; // 新行
  }
  if (flag == 241)
  {
    MsgHaddle t24=Msg.haddle24B(data_bin);

    new_line1.assign({timeStr, line_split[2], line_split[3], line_split[5], 
        to_string(t24.Type), to_string(t24.MMSI),to_string(t24.TransCount),
        to_string(t24.PartNum),to_string(t24.ShipType),to_string(t24.VendorID),
        to_string(t24.CallSign),to_string(t24.size_posRef)});
    for (size_t i = 0; i < new_line1.size(); ++i) 
    {
        outfile24B << new_line1[i] << "\t"; // 使用制表符作为列分隔符
    }
    outfile24B << std::endl; // 新行
  }
}
void File::logWrite(std::map<uint32_t,Numb> Infos)
{
  for (std::map<uint32_t,Numb>::iterator it = Infos.begin(); it != Infos.end(); ++it)
    {
      this->log<<"MMSI: "<<it->first<<" "<<it->second.count<<" "<<it->second.transmit<<" "<<it->second.Rate<<endl;
      this->log<<"    Freq: ";
      uint32_t count = 0; // 添加一个计数器
      for(uint32_t i = 0; i < it->second.freq.size(); i++)
      {
          this->log << it->second.freq[i] << " ";
          count++; // 每输出一个元素，计数器加1
          // 每当计数器达到30时，输出一个换行符，并重置计数器
          if(count == 80)
          {
              this->log << std::endl<<"   ";
              count = 0; // 重置计数器
          }
      }
      // 如果最后一行不足30个元素，也需要输出一个换行符
      if(count > 0)
      {
          this->log << std::endl;
      }
    }

}
