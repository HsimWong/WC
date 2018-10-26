# Team Module
import json
from Overall_func import *
from Player import *



class Team:
	def __init__(self, id_num):
		self.id_num = id_num
		self.team_name = id_team[self.id_num]
		# self.


if __name__ == '__main__':
	with open('processed_data\\team_num_play.json') as f:
		t_p = json.loads(f.read())

	with open('processed_data\\knockout_country_id.json') as f:
		id_team = dic_rev(json.loads(f.read()))

	# id_team = {}
	# for key in id_team_raw.keys():
	# 	id_team.update({id_team_raw[key]:key})
	# print(id_team)

	p1 = Player('Portugal', '1')