# coding:utf-8
import json
from webview.DataControl.Overall_func import *
from webview.DataControl import match_time
from webview.DataControl.Goal import *
from webview.DataControl.Team import *

with open('webview/DataControl/processed_data/teams.json') as f:
	participants = json.loads(f.read())

with open('webview/DataControl/processed_data/knockout_country_id.json') as f:
	team_ind = json.loads(f.read())

with open('webview/DataControl/Raw_data/worldcup.json', 'r') as f:
	raw_info = json.loads(f.read())

# goalbelong{"AWAY":}
'''
home = 64 - 2 * 64 + 2 * id = 2 * id - 64
away = 64 - （64 -p) * 2 + 1= 2 * id - 63
'''
'''
Definition of the node of binary tree
'''
class Match:
	'''
	Team which participates in this game is logically realized in the module of Playoff.py
	home_team and away_team are objects of Team
	'''
	def get_goal_string(self, goal):
		ret = str(goal.goal_time) + '\t'
		if goal.goal_goaler_team == "HOME":
			ret += self.home_team.players_list[goal.goaler_id].name
		else:
			ret += self.away_team.players_list[goal.goaler_id].name

		if goal.ifOG == True:
			ret += '\tOG'

		if goal.goaler_id == -1:
			ret += '\tPenalty'
		return ret
	
	def __init__(self, id_num, home_match, home_team, away_match, away_team):
		self.start_time = match_time.times[id_num]
		self.id = id_num
		self.home_match = home_match
		self.home_team = home_team
		self.away_match = away_match
		self.away_team = away_team
		self.home_goal_num = 0
		self.away_goal_num = 0
		# status rep
		self.status = (get_cur_time() > match_time.times[id_num]);
		self.raw_score_list = json.loads(open('webview/DataControl/processed_data/events/' + str(self.id) + '.json', 'r').read())
		self.score_list = []
		self.winner = None
		self.loser = None

		for score in self.raw_score_list:
			if (date_intp(score[0])) < get_cur_time():
				# print((date_intp(score[0])))
				# print(get_cur_time())
				temp = Goal(score)
				temp.str_info = self.get_goal_string(temp)
				self.score_list.append(temp)
				if temp.goal_belong == "HOME":
					self.home_goal_num += 1
					if self.id < 48:
						self.home_team.goal_win += 1
						self.away_team.goal_lose -= 1
					if (not temp.ifOG) & (temp.goaler_id >= 0):
						self.home_team.players_list[temp.goaler_id].goal_in(temp)
				else:
					self.away_goal_num += 1
					if self.id < 48:	
						self.away_team.goal_win += 1
						self.away_team.goal_lose -= 1					
					if not temp.ifOG:
						self.away_team.players_list[temp.goaler_id].goal_in(temp)
		if self.home_goal_num > self.away_goal_num:
			self.winner = home_team
			self.loser = away_team
			if self.id < 48:
				self.winner.credit += 3
				self.loser.credit += 0

		elif self.home_goal_num < self.away_goal_num:
			self.winner = away_team
			self.loser = home_team
			if self.id < 48:
				self.winner.credit += 3
				self.loser.credit += 0
		else:
			self.winner = None
			self.loser = None
			if self.id < 48:
				self.home_team.credit += 1
				self.away_team.credit += 1

	
	def get_start(self):
		return self.start_time

	def __lt__(self, other):
		return (self.id < other.id)

	def __le__(self, other):
		return (self.id <= other.id)

if __name__ == '__main__':
	# pass
	Match(1, None, None, None, None)