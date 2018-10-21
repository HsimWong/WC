import requests
import json
import datetime
from bs4 import BeautifulSoup as bs 


def get_match_list():
	print('start getting match_list')
	url_list = []
	url = 'https://www.fifa.com/worldcup/matches'
	r = str(requests.get(url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	match_idpars = bs_obj.findAll('a',{'class':'fi-mu__link'})
	for item in match_idpars:
		url_list.append('https://www.fifa.com' + item['href'])
	return url_list


def get_teams(url_list):
	
	total_parti = []
	for url in url_list:
		print(url)
		match = []
		r = str(requests.get(url).content, 'utf-8')
		bs_obj = bs(r, 'html.parser')
		team_parse = bs_obj.findAll('span', {'class':'fi-t__nText'})
		for temp in team_parse:
			match.append(temp.get_text())
		print(match)
		total_parti.append(match)

	return total_parti

if __name__ == '__main__':
	t = json.dumps(get_teams(get_match_list()))
	with open('teams.json','w') as f:
		f.write(t)

	