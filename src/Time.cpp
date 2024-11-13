#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
char* Time_(time_t timestamp) {
    
    tm *utc_time = gmtime(&timestamp); // 转换为 tm 结构体（UTC 时间）
    
    char* buffer = new char[80]; // 动态分配内存来存储格式化的时间字符串

    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", utc_time);
    return buffer;
}
std::string Time_Convert(uint32_t timestamp) 
{
    if( timestamp <60)
    {
        return std::to_string(timestamp) + "s";
    }
    else
    {
        return std::to_string(timestamp/60) + "m"+ std::to_string(timestamp%60) + "s";
    }
    
}
// int main() {
//     char* timeStr = Time_();
//     std::cout << timeStr << std::endl;
//     delete[] timeStr; // 释放内存
//     return 0;
// }