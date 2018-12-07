# coding = 'utf-8'
import PlayOff as po
from Overall_func import *

p = po.PlayOff()
total_players = []
for group in p.groups:
	for team in group.team_list:
		for player in team.players_list:
			total_players.append(player)

qs(total_players)
# print(len(total_players[767].goals))
total_players = total_players[::-1]
for player in total_players:
	if player.get_goal_number() == 0:
		break
	else:
		print(player.team, end = '\t\t')
		print(player.name, end = '\t\t\t')
		print(player.get_goal_number())
		