//
// Created by Hsim_WONG on 2018/9/12.
//

#ifndef BACKEND_MATCH_H
#define BACKEND_MATCH_H
#include<string>

class Match {
private:
	Date * matchDate;
	int matchNum;
	bool isGroup;
	Team * home;
	Team * away;
	int home_res;
	int away_res;
	int home_penalty;
	int away_penalty;
	bool isfinished;
	Team * winner;
public:
	Match(Date * now, matchNum){
		
	}
};


#endif //BACKEND_MATCH_H
