#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include "functions.h"
#include<fstream>
using namespace std;

class Match{
private:
	int match_id;
	Team * team_home;
	Team * team_away;
	vector<Goal *> goals;
	Team * team_win;
public:
	Match(int match_id);
	int get_match_id();
	Team * get_team_home();
	Team * get_team_away();
	vector<Goal *> get_goals();
	Team * get_team_win();
};


Match::Match(int match_id){
	this -> match_id = match_id;
	
	ifstream fh("Python\\processed_data\\event.json");
	string str;
	while(getline(handler,str)){
		if(str.size() > 10){
			for(int i = 0; i < str.size; i++){
				// Link stack here to store paranthesis
			}
		}
	}
};

int Match::get_match_id(){
	return this -> match_id;
}

Team * Match::get_team_home(){
	return this -> team_home;
}

Team * Match::get_team_away(){
	return this -> team_away;
}

vector<Goal *> Match::get_goals(){
	return this -> goals;
}

Team * Match::get_team_win(){
	return this -> team_win;
}