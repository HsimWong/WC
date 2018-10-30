# coding:utf-8
import json
from Overall_func import *

with open('processed_data\\teams.json') as f:
	participants = json.loads(f.read())

with open('processed_data\\knockout_country_id.json') as f:
	team_ind = json.loads(f.read())

'''
63 - 62）/2 + 1 = 

k = 63 - m
p = 63 - n
m = n * 2 - 1

64 - home = (64 - p) * 2
64 - away = (64 - p) * 2 - 1

home = 64 - 2 * 64 + 2 * id = 2 * id - 64
away = 


1
	3
		5
			9
			10
		6
			11
			12
	4
		7
			13
			14
		8
			15
			16

2
	3
	4

'''

class Match:
	def __init__(self, id_num):
		self.id = id_num
		self.home_team = None
		self.away_team = None
		self.home_son = None
		self.away_son = None
		self.winner = None
		self.loser = None
		get_teams()

	def if_group():
		return (self.id < 48)


	def get_teams:
		if if_group():
			self.home_team = Team(team_ind[participants[self.id][0]])
			self.away_team = Team(team_ind[participants[self.id][1]])
			return True
		elif self.id == 63:
			pass
		elif self.id == 62:
			pass
		elif self.id >= 56:
			pass
		else:
			pass






# class Match_group:
# 	def __init__(self, id):
# 		self.group = 
# 		self.match_id = id
# 		self.event_list = []
# 		self.
# 	def get_teams


# class Match_knock:
# 	def __init__(self, id):
# 		self.aim_match