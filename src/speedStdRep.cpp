#include<string>
#include "speedStdRep.h"
bool speedStdRep(uint32_t Time_period,float SOG, uint32_t NaviStatus)
{
    if(SOG <=3&&(NaviStatus==1||NaviStatus==5))
    {
        if(Time_period<=180)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(SOG > 3&&(NaviStatus==1||NaviStatus==5))
    {
         if(Time_period<=10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(SOG>=0&&SOG<14)
    {
        if(Time_period<=10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(SOG>=14&&SOG<23)
    {
        if(Time_period<=6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(SOG>23)
    {
        if(Time_period<=2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool speedStdRep(uint32_t Time_period,float SOG)