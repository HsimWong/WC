import json
import time
from datetime import *

cur_time = "2018-07-15 16:20:00"

def get_json_dic(directory):
	return json.loads(open(directory,'r').read())

def coh_date_time(date, time):
	return date + ' ' + time


# 2018-06-14 18:00:00
def date_intp(str):
	return datetime.strptime(str,'%Y-%m-%d %H:%M:%S')


def dic_rev(dic):
	ret = {}
	for key in dic.keys():
		ret.update({dic[key]:key})
	return ret

def get_cur_time():
	global cur_time
	return date_intp(cur_time)

def set_cur_time(str):
	global cur_time
	cur_time = datetime.strptime(str, '%Y-%m-%d %H:%M:%S')

if __name__ == '__main__':
	# print(time.time())
	# print(type(datetime.now()))
	print(type(date_intp('2018-06-14 18:00:00')))
	
	