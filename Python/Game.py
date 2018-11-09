# coding = 'utf-8'
import Overall_func as fc
import PlayOff as po 
from Match import *


p = po.PlayOff()
print(len(p.games))
for game in p.games:
	info = 'home:' + game.home_team.team_name + '\taway:'+game.away_team.team_name + '\tstatus:' + str(game.status) + '\tstar_time:' + str(match_time.times[game.id]) + '\t'
	goals = game.score_list
	goal_dic = {"HOME":game.home_team.team_name, "AWAY":game.away_team.team_name}
	print(info, end = '\n')
	for goal in goals:
		print(goal_dic[goal.goal_belong], end = ':')
		print(goal.goal_time, end = '\t')
		
	print('', end = '\n')
	