
#include<iostream>
#include<string>
using namespace std;

class Date {
public:
    int month;
    int day;
    int hour;

    Date(string RawDate);
    int month2Num(string month);
    int getDate();
};


Date::Date(string RawDate){
    // Fri Jun/15 17:00
    string RawMonth = "xxx";
    RawMonth[0] = RawDate[4];
    RawMonth[1] = RawDate[5];
    RawMonth[2] = RawDate[6];
    this -> month = month2Num(RawMonth);
    this -> day = (RawDate[8] - 48) * 10 + RawDate[9] - 48;
    this -> hour = (RawDate[11] - 48) * 10 + RawDate[12] - 48;
}

int Date::month2Num(string month){
    int ret = 0;
    if(month == "Jun"){
        ret = 6;
    }
    else if(month == "Jul"){
        ret = 7;
    }
    else{
        cerr << "Month Fault" << endl;
    }
    return ret;
}

int Date::getDate(){

    int ret = hour + day * 100 + month * 10000;
    return ret;
}

// int main(){
// 	string raw = "Fri Jun/15 17:00";
// 	Date * date = new Date(raw);
// 	int res = date ->getDate();
// 	cout << res << endl;
// 	cout << date -> month << endl;
// 	cout << date -> day << endl;
// 	cout << date -> hour << endl;
// 	system("pause");
// 	return 0;
// }
