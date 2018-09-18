# coding = 'utf-8'
# Match schedule
# total_member:[groupA:group_members_A, groupB:group_members_B]
class Player:
	def __init__(self, name):
		self.name = name
		self.Team = getTeam(file)
		self.goal = []
		self.foul = []
		self.yellow_card = []
		self.red_card = []
	def getTeam(self,file):
		pass

class Team:
	def __init__(self, name):
		self.name = name
		self.player_list = []

class Goal:
	def __init__(self,time,player,matchID):
		self.time = time
		self.player = player
		self.matchID = matchID



class Match:
	def __init__(str):
		self.teamA = getTeamA(str)
		self.teamB = getTeamB(str)
		self.matchID = genID(str)
		self.match_date = get_date(str)
		self.teamA_goal = get_goal_A(str)
		self.teamB_goal = get_goal_B(str)