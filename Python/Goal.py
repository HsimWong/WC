import json
from Overall_func import *
# ["2018-06-14 16:26:00", 0, "HOME", 22, false, "HOME"]


class Goal:
	"""docstring for Goal"""

	# The string input herer has to be attached with '[]'
	def __init__(self, string):
		self.info = json.loads(string)
		self.time = date_intp(self.info[0])
		self.match_id = self.info[1]
		self.goaler_team = self.info[2]
		self.goaler_id = self.info[3]
		self.ifOG = self.info[4]
		self.goal_belong = self.info[5]

	def get_time(self):
		return self.time

g = Goal('["2018-06-14 16:26:00", 0, "HOME", 22, false, "HOME"]')
print(g.get_time())