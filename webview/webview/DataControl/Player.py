# coding = 'utf-8'
import json
from webview.DataControl.Overall_func import *


with open('webview/DataControl/processed_data/team_num_play.json') as f:
	player_info = json.loads(f.read())

class Player:
	"""docstring for Player"""
	def __init__(self, team, number):
		self.team = team
		self.number = number
		self.name = player_info[team][str(number)]
		self.goals = []

	def goal_in(self, goal):
		self.goals.append(goal)

	def get_goal_number(self):
		return (len(self.goals))

	def __lt__(self, other):
		return (len(self.goals) < len(other.goals))

	def __le__(self, other):
		return (len(self.goals) <= len(other.goals))
		

# a = Player('Russia', "Coach")
# print(a.name)


