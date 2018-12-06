# -*- coding: utf-8 -*-
 
from django.http import HttpResponse
from django.shortcuts import render
from django.shortcuts import render_to_response
from webview.DataControl import Overall_func
from webview.DataControl import PlayOff
from webview.DataControl import Match

def search_match_page(request):
	return render_to_response('matches.html')

def search_match(request):
	context = {}
	if Overall_func.cur_time == "":
		return render(request, 'index.html', context)
	request.encoding='utf-8'
	match_id = request.GET['match_id']
	p = PlayOff.PlayOff()

	game = p.games[int(match_id)]

	context.update({
		'start_time':game.start_time,
		'home_team' :game.home_team.team_name,
		'away_team' :game.away_team.team_name,
		'score_list':game.score_list})
	return render(request, 'match_info.html', context)


# , 
