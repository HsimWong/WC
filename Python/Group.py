# coding = 'utf-8'
'''
This module is designed for managing matches 
	in group phase of a single group. Firstly, 
	the group manager runs self.games in this phase,
	and then push up teams that are qualified to the PlayOff
'''
from Team import *
import json
import match_time
from Goal import *
from Overall_func import *
from Match import *


with open('processed_data\\knockout_country_id.json') as f:
	team_id = json.loads(f.read())

with open('Raw_data\\worldcup.json', 'r') as f:
	match_exact_info = json.loads(f.read())

team_id.update({"Iran": "B2", "South Korea": "F2"})


# print(len(match_exact_info))
# print(match_exact_info['rounds'][0]['matches'][0]['num'])

class Group:
	def __init__(self, group_name):
		# Definition of teams
		self.group_name = str.upper(group_name)
		self.team_0 = Team(self.group_name + str(0))
		self.team_1 = Team(self.group_name + str(1))
		self.team_2 = Team(self.group_name + str(2))
		self.team_3 = Team(self.group_name + str(3))
		self.games = []
		# team_dic = {}
		# Procedure of self.games
		self.team_list = [self.team_0, self.team_1, self.team_2, self.team_3]
		team_dic = {self.group_name + str(0):self.team_0, 
				self.group_name + str(1):self.team_1, 
				self.group_name + str(2):self.team_2, 
				self.group_name + str(3):self.team_3}

		# self.self.games = []
		for match_day in match_exact_info['rounds']:
			for match in match_day['matches']:
				# print((match))
				if match['num'] < 49:
					if match['group'][-1] == self.group_name:
						
						self.games.append(Match(match['num'] - 1, None, team_dic[team_id[match['team1']['name']]], None, team_dic[team_id[match['team2']['name']]]))
		# print(self.games[0].away_goal_num)
		# print(self.games[0].home_goal_num)
		# print(self.games[0].id)
		# print(self.games[0].home_team.credit)
		# print(self.games[0].away_team.team_name)
		# print(self.games[0].score_list[0].goal_time)
		# print(self.games[1].id)
		qs(self.team_list)
		# print(team_list[0])
		# print(self.games[0].home_team.team_name)
if __name__ == '__main__':
	# groupa = Group('A')
	groupb = Group('B')
	print(groupb.games[0].id)
	print(groupb.games[0].away_goal_num)
	# print()
	# groupc = Group('F')
	a = get_cur_time()
	print(a)	
	# print(groupb.team_list[1].credit)


# a = Group("A")
# print(a.team_0.players_list[0].team)
