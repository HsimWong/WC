# coding = 'utf-8'

class Goal(object):
	"""docstring for Goal
	goal_obj is an element parsed by the json.loads(), whose format is as

	[String time, int game_id, string Goaler_team, int goaler_id, bool ifOG, string goal_belong]
	e.g.:
	[]

	 """
	def __init__(self, goal_obj):
		self.goal_time = goal_obj[0]
		self.goal_match_id = goal_obj[1]
		self.goal_goaler_team = goal_obj[2]
		self.goaler_id = goal_obj[3]
		self.ifOG = goal_obj[4]
		self.goal_belong = goal_obj[5]
		self.str_info = ""

	def set_info(self, string):
		self.str_info = string

		

	