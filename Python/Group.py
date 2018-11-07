# coding = 'utf-8'
'''
This module is designed for managing matches 
	in group phase of a single group. Firstly, 
	the group manager runs games in this phase,
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



print(len(match_exact_info))
print(match_exact_info['rounds'][0]['matches'][0]['num'])

class Group:
	def __init__(self, group_name):
		# Definition of teams
		self.group_name = str.upper(group_name)
		self.team_0 = Team(self.group_name + str(0))
		self.team_1 = Team(self.group_name + str(1))
		self.team_2 = Team(self.group_name + str(2))
		self.team_3 = Team(self.group_name + str(3))

		team_dic = {}
		# Procedure of games
		team_dic = {self.group_name + str(0):self.team_0, 
				self.group_name + str(1):self.team_1, 
				self.group_name + str(2):self.team_2, 
				self.group_name + str(3):self.team_3}

		games = []
		for match_day in match_exact_info['rounds']:
			for match in match_day['matches']:
				# print((match))
				if match['num'] < 49:
					if match['group'][-1] == self.group_name:
						# print(type(match['num']))
						print(match['team1'], end = '\t')
						print(match['team2'])
						games.append(Match(match['num'] - 1, None, team_dic[team_id[match['team1']['name']]], None, team_dic[team_id[match['team2']['name']]]))

if __name__ == '__main__':
	group = Group('A')

		


# a = Group("A")
# print(a.team_0.players_list[0].team)

