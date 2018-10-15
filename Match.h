#ifndef MATCH_H
#define MATCH_H value


#include<ctime>
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

// short match_status表示比赛的进行状态
// 0	未开赛
// 1	正在进行
// 2	已结束

class Match{
private:
	int match_id;
	short match_status = 0;
	time_t curr_time
	int num_goal_home;
	int num_goal_
	// Team * team_win;
public:
	Match(int match_id, string curr_time);
	void fetch_balls();
	int get_match_id();
	// Team * get_team_home();
	// Team * get_team_away();
	// vector<Goal *> get_goals();
	// Team * get_team_win();
};


Match::Match(int match_id, string time){
	this -> match_id = match_id;
	this -> curr_time = str2time(time);
	fetch_balls();
}

void Match::fetch_balls(){
	// file fetching
	if(true){
		string MID = to_string(match_id);
		string file_name = "Python\\processed_data\\events\\" + MID + ".json";
		ifstream fh(file_name);
		string str;
		getline(fh, str);
		
		Stack<char> * stk = new Stack<char>();
		stk -> push(',');
	}
	
	// temporary variable storage for goals
	if (true){
		int temp_match_id = -1;
		string temp_time = "";
		string temp_goaler_team = "";
		// int temp_match_id;
		int temp_goaler_id = -2;
		bool temp_ifOG = false;
		string temp_goal_belong = "";
	}

	int info_ind = 0;
	for(int i = 0; i < str.size(); i++){
		// info parsing
		if(true){
			string temp = "";
			if(str[i] == '[' || str[i] == ']' || str[i] == '"' || (str[i] == ' ' && str[i - 1] == ',')){
				continue;
			}
			else if(str[i] == ',' || i == (str.size() - 1)){
				do{
					temp = (stk -> top()) + temp;
					stk -> pop();
				}while(stk -> top() != ',');
			}
			else{
				stk -> push_back(str[i]);
			}
		}

		switch(info_ind){
			case 0:
				temp_time = temp;
				break;
			case 1:
				temp_match_id = str2int(temp);
				break;
			case 2:
				temp_goaler_team = temp;
				break;
			case 3:
				temp_goaler_id = str2int(temp);
				break;
			case 4:
				temp_ifOG = (temp == "true");
				break;
			case 5:
				temp_goal_belong = temp;
		}

		if((info_ind == 5) && (str2time(temp_time) <= curr_time)){
			if(temp_goal_belong = "HOME"){
				(this -> num_goal_home)++;
			}
			else if(temp_goal_belong = "")
		}





		info_ind = (info_ind + 1)%5

	}





	// getline(fh,str)){
	// 	string time = "";
	// 	int match_id = NULL;
	// 	string
	// 	Stack<char> * stk = new Stack<string>();

	// 	for(int i = 1; i < (int)str.size(); i++){
	// 		// if(str[i] == ',')continue;
	// 		if(str[i] == ']'){

	// 		}
		
	// }
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

