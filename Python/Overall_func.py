import json
import time
from datetime import *
def get_json_dic(directory):
	return json.loads(open(directory,'r').read())

def coh_date_time(date, time):
	return date + ' ' + time


# 2018-06-14 18:00:00
def date_intp(str):
	return datetime.strptime(str,'%Y-%m-%d %H:%M:%S')


if __name__ == '__main__':
	# print(time.time())
	# print(type(datetime.now()))
	print(type(date_intp('2018-06-14 18:00:00')))
	