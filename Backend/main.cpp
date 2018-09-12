#include<iostream>
#include<ctime>
#include<string>

using namespace std;
/*
 * This is the definition of a single match.
 * Each match is defined with 4-digit code.
 * e.g. The first match of the first round of group A is
 * defined as: 1111
 * where the 1st digit means group stage match;
 * 2nd digit means group A
 * 3rd means round 1
 * 4th means 1st match
 */
class Match{
private:
    time_t MatchTime;
    string host;
    string guest;
    int scoreHost;
    int scoreGuest;
public:
    Match();
    void getData();
    string Winner();
};

int main(){
//    time_t now = time(0);
//    cout << now;
//    string * dt = ctime(&now);
//    cout << dt << endl;
}