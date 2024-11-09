#include<iostream>

#include<string>
#include<bitset>
#include<vector>
#include<sstream>

std::string ais_charset = "!@#$%*+-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz(|)~";
std::string ais_decode(std::string &str,std::string& data_bin)
{
     for (auto char_ : str) 
     {
        // 查找字符是否在AIS字符集中
        size_t pos = ais_charset.find(char_);
        if (pos == std::string::npos) {
            std::cerr << char_ << " is not in ais_charset" << std::endl;
            break;
        }
        // 将字符转换为二进制并存储到data_bin中
        int value = static_cast<int>(char_);
        if(value>=0x30&&value<=0x57)
        {
            value=(value-48)&0x3F;
        }
        else if(value>=0x60&&value<=0x77)
        {
            value=(value-56)&0x3F;
        }
        std::bitset<6> bits(value);
        data_bin+=bits.to_string();  
     }
    return data_bin;
}


