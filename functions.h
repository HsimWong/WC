#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
time_t str2time(string s){
    struct tm tm;    
    const char * timeStamp = s.c_str();
    std::memset(&tm, 0, sizeof(tm));        
    sscanf(timeStamp, "%d-%d-%d %d:%d:%d",&tm.tm_year, &tm.tm_mon, &tm.tm_mday,&tm.tm_hour, &tm.tm_min, &tm.tm_sec);     
    tm.tm_year -= 1900;    
    tm.tm_mon--;     
    return mktime(&tm);
}



#endif