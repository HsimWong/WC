# -*- coding: utf-8 -*-
 
from django.http import HttpResponse
from django.shortcuts import render
from webview.DataControl import Overall_func
from webview.DataControl import PlayOff
# from webview.DataControl.Overall_func import *
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
	
	p = PlayOff.PlayOff()
	context.update({
		'groups':p.groups
		})

	return render(request, 'groups.html', context)









def score_rank(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)

	else:
		p = PlayOff.PlayOff()
		total_players = []
		for group in p.groups:
			for team in group.team_list:
				for player in team.players_list:
					goal_num = len(player.goals)
					if not goal_num == 0:
						total_players.append(player)

		Overall_func.qs(total_players)
		total_players.reverse()
		context['score_list'] = total_players
		return render(request, 'score_rank.html', context)
	

def players(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	

