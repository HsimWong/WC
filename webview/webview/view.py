# -*- coding: utf-8 -*-
 
from django.http import HttpResponse
from django.shortcuts import render
from webview.DataControl import Overall_func
from webview.DataControl import PlayOff
def hello(request):
    context          = {}
    context['hello'] = 'Hello World!'
    return render(request, 'hello.html', context)

def first(request):
	context = {}
	return render(request, 'index.html', context)


def matches(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	p = PlayOff.PlayOff()
	
	context.update({'time': str(Overall_func.cur_time), 'matches': p.games})
	return render(request, 'matches.html', context)



def teams(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	p = PlayOff.PlayOff()

	return render(request, 'teams.html', context)

def groups(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	

def score_rank(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	

def players(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	

