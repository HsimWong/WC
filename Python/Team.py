# Team Module
import json
from Overall_func import *



class Team:
	def __init__(self, id_num):
		self.id = id_num


if __name__ == '__main__':
	with open('processed_data\\team_num_play.json') as f:
		t_p = json.loads(f.read())

	with open('processed_data\\knockout_country_id.json') as f:
		id_team_raw = json.loads(f.read())

	id_team = {}
	for key in id_team_raw.keys():
		id_team.update({id_team_raw[key]:key})
	print(id_team)