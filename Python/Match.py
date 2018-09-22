# coding = 'utf-8'
# Match schedule
# total_member:[groupA:group_members_A, groupB:group_members_B]
import json

def get_json_dic(directory):
	return json.loads(open(directory,'r').read())

class TeamPlayerList:
	def __init__(self, country):
		self.team_name = country
		self.player_list = []
		self.player_dic_gen()

	def player_dic_gen(self):
		for player in get_json_dic('Raw_data/squad.json'):
			if player['country'] == self.team_name:
				self.player_list.append(player)

class Player:
	def __init__(self,name):
		self.name = name
		self.goal_list = []

	def ini_goal_list(self):
		pass

class Goal:
	def __init__(self,)


dic = get_json_dic('Raw_data/worldcup.json')
match_ind_day = 0
f = dic['rounds'][match_ind_day]['matches'][0]['goals1'][2]
print(type(f))
print(f)







