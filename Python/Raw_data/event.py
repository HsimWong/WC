import requests
import json
import datetime
from bs4 import BeautifulSoup as bs 

def get_event_list(match_url):
	timezone = {
		"Samara":4,
		"Nizhny Novgorod":3,
		"Volgograd":3,
		"Ekaterinburg":5,
		"Saransk":3,
		"Rostov-on-Don":3,
		"Kaliningrad":2,
		"Kazan":3,
		"Sochi":3,
		"Saint Petersburg":3,
		"Moscow":3
	}

	r = str(requests.get(match_url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	goal_list_pars = bs_obj.findAll('span',{'class':'fi-p__nShorter '})
	goal_time_pars = bs_obj.findAll('span', {'class':'fi-mh__scorer__minute'})
	start_time = bs_obj.findAll('div',{'class':'fi-mu__info__datetime'})[0].get_text()
	start_time = start_time[start_time.find(' 2018') - 6:start_time.find(' 2018') + 13]
	# p
	# print(datetime_struct.strftime('%d %m %Y - %H:%M'))
	start_time = datetime.datetime.strptime(start_time,'%d %b %Y - %H:%M')
	# print(str(start_time))
	# print(type(start_time))
	goal_list = {}
	# goal_time = []
	for i in range(len(goal_list_pars)):
		string = goal_list_pars[i].get_text()
		time = goal_time_pars[i].get_text().split()[0]

		if not string[0] == '@':
			if not len(time) == 3:
				time = str(int(time[0:2]) + int(time[len(time) - 2]))
			else:
				time = time[0:2]
			if int(time) >= 45:
				time = str(int(time) + 15)

			full_time = str(start_time + datetime.timedelta(minutes = int(time)))
			goal_list.update({full_time:string})

	# for time_par in goal_time

	print((goal_list))

# GMT
# def get_match_time

def get_match_list




url = 'https://www.fifa.com/worldcup/matches/match/300331503/#match-lineups'
get_event_list(url)