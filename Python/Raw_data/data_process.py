# coding = 'utf-8'
import json

class TeamPlayerList:
	def __init__(self, country):
		self.team_name = country
		self.player_list = []
		player_dic_gen()

	def player_dic_gen():
		for player in json.loads(open('squad.json','r')):
			if player['country'] == self.team_name:
				self.player_list.append(player)

