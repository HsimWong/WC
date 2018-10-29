# Team Module
import json
from Overall_func import *
from Player import *

# Global variables
with open('processed_data\\team_num_play.json') as f:
	t_p = json.loads(f.read())

with open('processed_data\\knockout_country_id.json') as f:
	id_team = dic_rev(json.loads(f.read()))



class Team:
	def __init__(self, id_num):
		self.id_num = id_num
		self.team_name = id_team[self.id_num]
		self.players_list = get_players()
		self.credit = 0

	def get_players():
		ret = []
		for i in range(24):
			if i == 0:
				ret.append(Player(team_name, t_p[self.team_name]['Coach']))
			else:
				ret.append(Player(team_name, t_p[self.team_name][str(i)]))
		return ret



	def win():
		self.credit += 3

	def peace():
		self.credit += 1

	def lose():
		pass



if __name__ == '__main__':
	p1 = Player('Portugal', '2')
	print(p1.name)
