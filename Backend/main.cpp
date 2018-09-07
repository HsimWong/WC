#include<iostream>
#include<ctime>
#include<string>

using namespace std;
/*
 * This is the definition of a single match.
 * The name of the match is defined
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
    time_t now = time(0);
    char * dt = ctime(&now);
    cout << dt << endl;
}