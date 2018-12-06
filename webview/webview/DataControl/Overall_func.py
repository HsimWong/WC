import json
import time
from datetime import *
import math
from webview.DataControl import match_time


cur_time = ""
# cur_time = 
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

def get_time_str():
	global cur_time
	return cur_time
# rec_arr is the record array
# left is the left opeation index
# while right is the right operation index
def qs(rec_arr):
	quick_sort(rec_arr, 0, len(rec_arr) - 1)

def quick_sort(rec_arr, left, right):
	if(right <= left):
		return
	pivot = math.floor((left + right) / 2)
	rec_arr[pivot], rec_arr[right] = rec_arr[right], rec_arr[pivot]
	pivot = Partition(rec_arr, left, right)
	quick_sort(rec_arr, left, pivot - 1)
	quick_sort(rec_arr, pivot + 1, right)

def Partition(rec_arr, left, right):
	l = left
	r = right
	temp_rec = rec_arr[r]
	while l < r:
		while (rec_arr[l] <= temp_rec) and (r > l):
			l += 1
		if l < r:
			rec_arr[r] = rec_arr[l]
			r -= 1
		while (rec_arr[r] >= temp_rec) and (r > l):
			r -= 1
		if l < r:
			rec_arr[l] = rec_arr[r]
			l += 1
	rec_arr[l] = temp_rec
	return l

# "2018-07-29 19:40:00"

def set_cur_time(str):
	global cur_time
	# cur_time = datetime.strptime(str, '%Y-%m-%d %H:%M:%S')
	cur_time = str



