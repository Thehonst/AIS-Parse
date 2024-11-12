#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include"split.h"
using namespace std;
void split(std::string line,vector<string>& line_split,char char_)
{
    
    istringstream tokenStream(line);
    string token;
    while (std::getline(tokenStream, token, char_))
    {
        line_split.push_back(token);
    } 
}