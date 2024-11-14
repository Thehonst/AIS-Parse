#include<string>
#include"boatlog.h"
#include "speedStdRep.h"
std::string speedStdRep(uint32_t Time_period,float SOG, uint32_t NaviStatus)
{
    if(SOG <=3&&(NaviStatus==1||NaviStatus==5))
    {
        if(Time_period<=180)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    if(SOG > 3&&(NaviStatus==1||NaviStatus==5))
    {
         if(Time_period<=10)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    if(SOG>=0&&SOG<14)
    {
        if(Time_period<=10)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    if(SOG>=14&&SOG<23)
    {
        if(Time_period<=6)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    if(SOG>23)
    {
        if(Time_period<=2)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    return "true";
}
std::string speedStdRep(uint32_t Time_period,float SOG,Numb::AISType AIS_Type)
{
    if(AIS_Type==Numb::AISType::B)
    {
        if(SOG<2)
        {
            if(Time_period<=180)
            {
                return "true";
            }
            else
            {
                return "false";
            }
        }
        if(SOG>=2&&SOG<14)
        {
            if(Time_period<=30)
            {
                return "true";
            }
            else
            {
                return "false";
            }
        }
        if(SOG>=14&&SOG<23)
        {
            if(Time_period<=15)
            {
                return "true";
            }
            else
            {
                return "false";
            }
        }
        if(SOG>=23)
        {
            if(Time_period<=5)
            {
                return "true";
            }
            else
            {
                return "false";
            }
        }
    }
    if(AIS_Type==Numb::AISType::AtoN)
    {
        if(SOG<180)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    if(AIS_Type==Numb::AISType::AIST)
    {
        if(SOG<10)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
    return "true";
        
}
