#ifndef TIME_H
#define TIME_H
#include <ctime>
#include <iomanip>
char* Time_(time_t timestamp);
std::string Time_Convert(uint32_t timestamp); 
#endif // TIME_H