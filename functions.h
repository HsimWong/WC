#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<cstring>
#include<ctime>
#include<fstream>
#include<vector>
#include<math.h>
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

long long power(long long root, long long times){
	long long ago = 1;
	for(int i = 0; i < times; i++){
		ago *= root;
	}
	return ago;
}

long long str2int(string s){
	long long ago = 0;
	bool ifneg = (s[0] == '-');
	int i = 0;
	if(ifneg){
		i = 1;
	}

	for(; i < (int)(s.size()); i++){
		if(s[i] <= '9' && s[i] >='0'){
			// cout << s[i] << '\t';
			// cout << (int)s[i] << '\t';
			// Result is inaccurate when digit number is greater than 4
			// ago += ((int)s[i] - 48) * ((double)pow(10.0, s.size() - (double)i - 1.0));
			ago += ((int)s[i] - 48) * (power(10,(int)(s.size() - i - 1)));
			// cout << ago << endl;
		}
		else{
			cerr << "the string input is not an integer" << endl;
			cerr << "Error occurrd at the " << i << "th digit of"<< s << endl;
			break; 
		}
	}
	if(ifneg){
		ago = (long long)0 - ago;
	}
	return ago;
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