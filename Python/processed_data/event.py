import requests
import json
import datetime
from bs4 import BeautifulSoup as bs 




def get_event_list(match_url):
	global match_id
	teams = {}
	goal_list = []
	timezone = {"Samara":4,"Nizhny Novgorod":3,"Volgograd":3,
		"Ekaterinburg":5,"Saransk":3,"Rostov-On-Don":3,"Kaliningrad":2,
		"Kazan":3,"Sochi":3,"St. Petersburg":3,"Moscow":3
	}

	r = str(requests.get(match_url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	# Venue
	venue = bs_obj.findAll("span",{'class':"fi__info__venue"})[0].get_text()
	# Start time GMT
	jet_lag = timezone[venue]
	start_time = bs_obj.findAll('div',{'class':'fi-mu__info__datetime'})[0].get_text()
	start_time = datetime.datetime.strptime(start_time[start_time.find(' 2018') - 6:start_time.find(' 2018') + 13],'%d %b %Y - %H:%M')
	# Get participants of the game
	team_parse = bs_obj.findAll('span',{'class':"fi-t__nText "})
	team_list = []
	for h in team_parse:
		team_text = h.get_text()
		if not team_text[-4:] == 'NAME':
			team_list.append(team_text)
	teams.update({team_list[0]: team_list[1], team_list[1]:team_list[0]})
# Here is for goals in regular time
	score_list = bs_obj.findAll('div', {'class':'fi-mh__scorer__event'})
	for i in range(len(score_list)):
		player_name = score_list[i].findAll('span',{'class':"fi-p__nShorter "})[0].get_text()
		time = score_list[i].findAll('span',{'class':"fi-mh__scorer__minute"})[0].get_text()
		try:
			og = (score_list[i].findAll('span',{'class':'fi-mh__scorer__label'})[0].get_text() == "OG")
		except:
			og = False
		if not player_name[0] == '@':
			player_num = tmi[player_name][0]
			goaler_team_id = tid[tmi[player_name][1]]
			# ind = (player_num, team_id)
			minute = int(time[0:time.find("'")])

			if(int(time.find("+")) + 1):
				stpg = int(time[time.find("+")+1])
			else:
				stpg = 0

			if minute > 45:
				minute += 15
			elif minute > 90:
				minute += 5
			time = minute + stpg

			full_time = str(start_time + datetime.timedelta(minutes = int(time)) - datetime.timedelta(hours = jet_lag))
			# goal_ind += 1
			if og:
				goal_belong = tid[teams[tmi[player_name][1]]]

			else:
				goal_belong = goaler_team_id
			ind = [full_time, match_id, goaler_team_id, player_num, og, goal_belong]
			goal_list.append(ind)
			# goal_list.update({full_time:ind})

		else:
			pass

	# This part is for goals in penalty
	# As goals in penalty period is not counted in goal ranking, so
	# the players who goals in penalty after 120 min are marked as -1
	penalty_goal_time = str(start_time + datetime.timedelta(minutes = 140))






	print(goal_list)
	match_id += 1
	return goal_list

def get_match_list():
	url_list = []
	url = 'https://www.fifa.com/worldcup/matches'
	r = str(requests.get(url).content,'utf-8')
	bs_obj = bs(r,'html.parser')
	match_idpars = bs_obj.findAll('a',{'class':'fi-mu__link'})
	for item in match_idpars:
		url_list.append('https://www.fifa.com' + item['href'])
	return url_list

if __name__ == '__main__':
	with open('team_member_info.json','r') as f:
		tmi = f.read()
	with open('Knockout_country_id.json','r') as f:
		tid = f.read()
	tid = json.loads(tid)
	tmi = json.loads(tmi)

	print(len(tid))
	print(len(tmi))

	match_id = 0
	urls = get_match_list()
	# print(match_id)
	data = []
	for url in urls:
		data.extend(get_event_list(url))

	jso = json.dumps(data)
	with open("event.json",'w') as f:
		f.write(jso)

	print("ok")

