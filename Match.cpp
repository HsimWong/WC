#include<iostream>
#include<string>
#include<cstdio>
#include "functions.h"

using namespace std;
#ifndef GOAL_H
#define GOAL_H
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
	bool operator < (Goal * g);
	bool operator <= (Goal * g);
	bool operator == (Goal * g);
	bool operator > (Goal * g);
	bool operator >= (Goal * g);
	bool isHappened(string t);
};

bool Goal::isHappened(string t){
	return (str2time(t) > str2time(this -> time));
}

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

bool Goal::operator < (Goal * g){
	return str2time(this -> time) < str2time(g -> time);
}

bool Goal::operator <= (Goal * g){
	return str2time(this -> time) <= str2time(g -> time);
}
bool Goal::operator >= (Goal * g){
	return str2time(this -> time) >= str2time(g -> time);
}

bool Goal::operator == (Goal * g){
	return str2time(this -> time) == str2time(g -> time);
}

bool Goal::operator > (Goal * g){
	return str2time(this -> time) > str2time(g -> time);
}


int main(){
	Goal * a = new Goal("2018-06-16 11:36:00", 4, "C3", 16, true, "C0");
	Goal * b = new Goal("2018-06-21 12:38:00", 20, "C3", 15, false, "C3");
	cout << (a > b) << endl;
}


#endif
