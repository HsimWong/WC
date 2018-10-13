#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<cstring>
#include<ctime>
#include<fstream>
#include<vector>
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



// vector<vector<string>> readFile(string file){
//     ifstream handler(file);
//     string str;
//     vector<vector<string>> vec;
//     while(getline(handler, str)){
//         if(str.size() > 10){
//             while( (index = s.find(' ',index)) != string::npos){
//                 s.erase(index,1);
//             }
//             string temp = str.substr(2,str.size() - 3);
//             int pos = 0;
//             vector<string> row;
//             do{
//                 int ind = temp.find(",", pos);
//                 if(ind >= 0 && ind < temp.size()){
//                     row.push_back(temp.substr(pos, ind - pos));
//                 }
//                 else{
//                     break;
//                 }
//             }while(true);
//             vec.push_back(row);
//         }
//     }
//     handler.close();
//     return vec;
// }




#endif