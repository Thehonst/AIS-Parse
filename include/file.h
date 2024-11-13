#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <string>
#include<sstream>
#include <vector>
#include <map>
#include "type_haddle.h"
#include"boatlog.h"
class File
{
public:
    File();
    ~File();
    void createFile();
    void openFile();
    void createHeader();
    void contentWrite(char* timeStr,std::vector<std::string> &line_split,
                        std::string data_bin,std::vector<std::string> &new_line1,int flag);
    void logWrite(std::map<uint32_t,Numb> Infos);
    std::vector<std::string> headers1;
    std::vector<std::string> headers5;
    std::vector<std::string> headers21;
    std::vector<std::string> headers24A;
    std::vector<std::string> headers24B;
    std::ofstream outfile1;
    std::ofstream outfile5;
    std::ofstream outfile21;
    std::ofstream outfile24A;
    std::ofstream outfile24B;

    std::ofstream log;
    //std::string str1="/home/mzf/data/动态数据.txt";
};


#endif