# coding = 'utf-8'
'''
This module is designed for managing matches 
	in group phase of a single group. Firstly, 
	the group manager runs games in this phase,
	and then push up teams that are qualified to the PlayOff
'''
from Team import *
import json
import match_time
from Goal import *
from Overall_func import *

class Group:
	def __init__(self, group_name):
		self.group_name = str.upper(group_name)
		self.team_1 = Team(self.group_name + str(1))
		
