# coding = 'utf-8'
# Team Module
import json
from webview.DataControl.Overall_func import *
from webview.DataControl.Player import *

# Global variables
with open('webview/DataControl/processed_data/team_num_play.json') as f:
	t_p = json.loads(f.read())

with open('webview/DataControl/processed_data/knockout_country_id.json') as f:
	id_team = dic_rev(json.loads(f.read()))



class Team:
	
	def __init__(self, id_num):
		self.goal_win = 0
		self.goal_lose = 0
		self.id_num = id_num
		self.team_name = id_team[self.id_num]
		self.players_list = [Player(self.team_name, 'Coach'),]+[Player(self.team_name, i + 1) for i in range(23)]
		self.credit = 0
		
	def __lt__(self, other):
		if self.team_name == "Japan" and other.team_name == "Senegal":
			return False
		return self.credit < other.credit

	def __eq__(self, other):
		if self.team_name == "Japan" and other.team_name == "Senegal":
			return False
		return self.credit == other.credit

	def __le__(self, other):
		if self.team_name == "Japan" and other.team_name == "Senegal":
			return False
		return self.credit <= other.credit
	def __gt__(self, other):
		if self.team_name == "Japan" and other.team_name == "Senegal":
			return True
		return self.credit > other.credit
		
	def win(self):
		# self.total_win += 1
		# if get_cur_time() <= 
		self.credit += 3
	def peace(self):
		self.credit += 1
	def lose(self):
		pass



if __name__ == '__main__':
	team_a = Team('A1')
	team_b = Team("B1")
	team_c = Team('C1')
	team_a.win()
	print(team_a.id_num)
	print(team_a.team_name)
	print(team_a.players_list[3].name)
	print(team_a.goal_win)
	print(team_a.credit)
	print(team_a < team_b)
	print(team_c <= team_b)
	# print()

	# print(team_a.players_list[0].name)
