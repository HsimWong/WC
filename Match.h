#ifndef MATCH_H
#define MATCH_H value



#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include "Goal.h"
#include "Stack.h"
#include "functions.h"


#include<fstream>
using namespace std;


// 淘汰赛阶段，每场比赛队伍分为home队和away队
// 每场比赛的胜利者队伍作为Team对象传递给上一组



class Match{
private:
	int match_id;
	// Team * team_home;
	// Team * team_away;
	// vector<Goal *> goals;
	// Team * team_win;
public:
	Match(int match_id);
	int get_match_id();
	// Team * get_team_home();
	// Team * get_team_away();
	// vector<Goal *> get_goals();
	// Team * get_team_win();
};


Match::Match(int match_id){
	this -> match_id = match_id;
	string MID = to_string(match_id);
	string file_name = "Python\\processed_data\\events\\" + MID + ".json";
	ifstream fh(file_name);
	string str;
	while(getline(fh,str)){
		string info;
		Stack<string> * stk = new Stack<string>();
		// for(int i = 0; i < (int)str.size(); i++){
			// if(str)
			// Link stack here to store paranthesis

		
	}
};

int Match::get_match_id(){
	return this -> match_id;
}

// Team * Match::get_team_home(){
// 	return this -> team_home;
// }

// Team * Match::get_team_away(){
// 	return this -> team_away;
// }

// vector<Goal *> Match::get_goals(){
// 	return this -> goals;
// }

// Team * Match::get_team_win(){
// 	return this -> team_win;
// }

#endif

