# -*- coding: utf-8 -*-
 
from django.http import HttpResponse
from django.shortcuts import render_to_response
from webview.DataControl import Overall_func
# 表单
def search_form(request):
	return render_to_response('index.html')

# 接收请求数据
def search(request):  
	request.encoding='utf-8'
	if 'date' in request.GET:
		time = request.GET['date'] + ' ' 
		if request.GET['time'] == '':
			time += "00:00"
		else:
			time += request.GET['time']
		time += ':00'
		Overall_func.set_cur_time(str(time))
		return HttpResponse("Current time: " + str(Overall_func.cur_time))
	else:
		return HttpResponse("Current time not set")

