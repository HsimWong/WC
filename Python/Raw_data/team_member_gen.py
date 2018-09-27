# coding = 'utf-8'
import json
# KSA		https://www.fifa.com/worldcup/teams/team/43835/
# RUS		https://www.fifa.com/worldcup/teams/team/43965/
# span class="fi-p__num"
# span class="fi-p__nShorter "

import requests
from bs4 import BeautifulSoup as bs


# dic_rus = get_player_dic("https://www.fifa.com/worldcup/teams/team/43965/")
# class="fi-o-media-object__link"

# This function is for getting the url of the detailed page
def get_team_url_list():
    ret = []
    addr = 'https://www.fifa.com/worldcup/teams/'
    r = requests.get(addr).text
    bs_obj = bs(r, "html.parser")
    teams = bs_obj.findAll("a", {"class": "fi-o-media-object__link"})
    # res = int(str(listo[0])[62:67])
    for team in teams:
        ret.append("https://www.fifa.com/worldcup/teams/team/" + (str(team)[62:67]))
        # print(str(team)[62:67])
    return ret


# The function get_player_dic is written for getting the player list of given team
def get_player_dic(url):
	ret = {}
	r = str(requests.get(url).content,'utf-8')
	bs_obj = bs(r,"html.parser")
	person_tab = bs_obj.findAll("div",{'class':"fi-p__n"})
	num_list = bs_obj.findAll("span",{'class':'fi-p__num'})
	team_name = str(bs_obj.findAll('title'))
	start_ind = team_name.find('Teams') + 8
	end_ind = team_name.find('- ',start_ind) - 2
	team_name = team_name[start_ind:end_ind]
	# print(team_name)
	# print((num_list))
	for i in range(len(person_tab)):
		if i < 23:
			num = num_list[i].get_text()
		elif i == 23:
			num = 'Coach'
		span = str((person_tab)[i].findAll("span"))
		begin_ind = span.find('>')
		end_ind = span.find('</span>')
		name = span[begin_ind+1:end_ind]
		ret.update({name:num})
	return team_name,ret

def team_gen():
	team_urls = get_team_url_list()
	info_dic = {}

	for url in team_urls:
		team, player_list = get_player_dic(url)
		info_dic.update({team:player_list})

	return info_dic


if __name__ == '__main__':
	jso = json.dumps(team_gen())
	with open("team_member_info.json",'w') as f:
		f.write(jso)