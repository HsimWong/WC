# coding: 'utf-8'
import json
from Overall_func import *
# from Team
from Group import *
import math




class PlayOff():
	# """docstring for PlayOff"""
	def __init__(self):
		self.games = []
		self.groups = []
		# self.id = id_num
		self.knock_id = {}
		def prm(string):
			return self.knock_id[string[0]][int(string[1])]
		self.game_8 = []
		self.game_4 = []
		self.game_2 = []
		
		count = 48
		self.game_8 = []
		for i in range(8):
			# temp = Group(chr(ord('A') + i))
			# self.groups.append(temp)
			gn = chr(ord('A') + i)
			temp_group = Group(gn)
			self.games.extend(temp_group.games)
			self.groups.append(temp_group)
			promo = [temp_group.team_list[3], temp_group.team_list[2]]
			self.knock_id.update({gn:promo})
		if get_cur_time() >= date_intp("2018-06-28 19:07:00"):
			
			# self.
			for i in range(8):
				# if i == 
				temp_tran = {1:0, 0:1}
				home_id = chr(ord('A') + i) + str(0)
				away_id = chr(ord('A') + temp_tran[i % 2] + math.floor(i / 2) * 2) + str(1)
				tp = Match(count, None, prm(home_id), None, prm(away_id))
				self.game_8.append(tp)
				self.games.append(tp)
				count += 1
			# print(self.groups[i].team_list[3])

		if get_cur_time() >= date_intp("2018-07-03 23:30:00"):
			'''
			home = 64 - 2 * 64 + 2 * id = 2 * id - 64
			away = 64 - （64 -p) * 2 + 1= 2 * id - 63
			'''
			for i in range(4):
				tp = Match(count, self.game_8[i * 2], self.game_8[i * 2].winner, self.game_8[i * 2 + 1], self.game_8[i * 2 + 1].winner)
				self.game_4.append(tp)
				self.games.append(tp)
				count += 1

		if get_cur_time() >= date_intp("2018-07-07 23:20:00"):
			for i in range(2):
				tp = Match(count, self.game_4[i * 2], self.game_4[i * 2].winner, self.game_4[i * 2 + 1], self.game_4[i * 2 + 1].winner)
				self.game_2.append(tp)
				self.games.append(tp)
				count += 1

		if get_cur_time() >= date_intp("2018-07-11 18:05:00"):
			self.game_bronze = Match(count, self.game_2[0], self.game_2[0].loser, self.game_2[1], self.game_2[1].loser)
			self.games.append(self.game_bronze)


		if get_cur_time() >= date_intp("2018-07-14 16:14:00"):
			self.final = Match(count, self.game_2[0], self.game_2[0].winner, self.game_2[1], self.game_2[1].winner)
			self.games.append(self.final)
# f = PlayOff()