# coding: 'utf-8'
import json
from Overall_func import *
# from Team
from Group import *
import math




class PlayOff():
	# """docstring for PlayOff"""
	def __init__(self):
		
		self.groups = []
		# self.id = id_num
		self.knock_id = {}
		def prm(string):
			return knock_id[string[0]][int(string[1])]
		self.game_8 = []
		self.game_4 = []
		self.game_2 = []
		
		id_count = 48
		if get_cur_time() >= date_intp("2018-06-28 19:07:00"):
			self.game_8 = []
			for i in range(8):
				# temp = Group(chr(ord('A') + i))
				# self.groups.append(temp)
				gn = chr(ord('A') + i)
				temp_group = Group(gn)
				self.groups.append(temp_group)
				promo = [temp_group.team_list[3], temp_group.team_list[2]]
				self.knock_id.update({gn:promo})
			for i in range(8):
				temp_tran = {1:0, 0:1}
				home_id = chr(ord('A') + i) + str(0)
				away_id = chr(ord('A') + temp_tran[i % 2] + math.floor(i / 2) * 2) + str(1)
				self.game_8.append(Match(count, None, prm(home_id), None, prm(away_id)))
				count += 1
			# print(self.groups[i].team_list[3])

		if get_cur_time() >= date_intp("2018-07-03 23:30:00"):
			for i in range(4):
				self.game_4

f = PlayOff()
for i in range(8):
	temp_tran = {1:0, 0:1}
	home_id = chr(ord('A') + i) + str(0)
	away_id = chr(ord('A') + temp_tran[i % 2] + math.floor(i / 2) * 2) + str(1)
	print(home_id, end = '\t')
	print(away_id)