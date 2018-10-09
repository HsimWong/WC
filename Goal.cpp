#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

class Goal{
private:
	string time;
	int match_id;
	string goalerTeamCode;
	int goaler_id;
	bool ifOG;
	string goal_belong;
public:
	Goal(string time, int match_id, string goalerTeamCode, int goaler_id, bool ifOG, string goal_belong);
	string get_time();
	int get_match_id();
	string get_goalerTeamCode();
	int get_goaler_id();
	bool get_ifOG();
	string get_goal_belong();
};

Goal::Goal(string time, int match_id, string goalerTeamCode, int goaler_id, bool ifOG, string goal_belong){
	this -> time = time;
	this -> match_id = match_id;
	this -> goalerTeamCode = goalerTeamCode;
	this -> goaler_id = goaler_id;
	this -> ifOG = ifOG;
	this -> goal_belong = goal_belong;
};

string Goal::get_time(){
	return this -> time;
}

int Goal::get_match_id(){
	return this -> match_id;
}

string Goal::get_goalerTeamCode(){
	return this -> goalerTeamCode;
}

int Goal::get_goaler_id(){
	return this -> goaler_id;
}

bool Goal::get_ifOG(){
	return this -> ifOG;
}

string Goal::get_goal_belong(){
	return this -> goal_belong;
}

int main(){
	cout << "hello";
}