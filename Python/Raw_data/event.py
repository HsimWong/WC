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
		"Rostov-On-Don":3,
		"Kaliningrad":2,
		"Kazan":3,
		"Sochi":3,
		"St. Petersburg":3,
		"Moscow":3
	}

	r = str(requests.get(match_url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	goal_list_pars = bs_obj.findAll('span',{'class':'fi-p__nShorter '})
	goal_time_pars = bs_obj.findAll('span', {'class':'fi-mh__scorer__minute'})
	venue = bs_obj.findAll("span",{'class':"fi__info__venue"})[0].get_text()
	jet_lag = timezone[venue]





	start_time = bs_obj.findAll('div',{'class':'fi-mu__info__datetime'})[0].get_text()
	start_time = start_time[start_time.find(' 2018') - 6:start_time.find(' 2018') + 13]
	start_time = datetime.datetime.strptime(start_time,'%d %b %Y - %H:%M')

	goal_list = {}
	# goal_time = []
	for i in range(len(goal_list_pars)):
		string = goal_list_pars[i].get_text()
		time = goal_time_pars[i].get_text().split()[0]
		print(time)
		if not string[0] == '@':
			# if not len(time) == 3:
			# 	time = str(int(time[0:time.find("'")]) + int(time[len(time) - 2]))
			# else:
			# 	time = time[0:2]
			# if int(time) >= 45:
			# 	time = str(int(time) + 15)
			# 	elif int(time) >
			minute = int(time[0:time.find("'")])

			if(int(time.find("+")) + 1):
				stpg = int(time[time.find("+")+1])
			else:
				stpg = 0

			print('stpg',end = "")
			print(stpg)

			if minute > 45:
				minute += 15
			elif minute > 90:
				minute += 5
			time = minute + stpg

			print('time:',end = "")
			print(time)
			full_time = str(start_time + datetime.timedelta(minutes = int(time)) - datetime.timedelta(hours = jet_lag))
			goal_list.update({full_time:string})
	return goal_list

def get_match_list():
	url_list = []
	url = 'https://www.fifa.com/worldcup/matches/#groupphase'
	r = str(requests.get(url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	id_pars = bs_obj.findAll('a',{'class':'fi-mu__link'})
	for item in id_pars:
		url_list.append('https://www.fifa.com' + item['href'])
	return url_list

if __name__ == '__main__':
	# url_list = get_match_list()
	# event_list = []
	# for url in url_list:
	# 	print(url)
	# 	event_list.extend(get_event_list(url))

	# jso = json.dumps(event_list)
	# with open('event_list.json','w') as f:
	# 	f.write(jso)
	url = 'https://www.fifa.com/worldcup/matches/match/300331509/'
	print(get_event_list(url))