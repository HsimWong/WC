import requests
from bs4 import BeautifulSoup as bs 
import json

url = 'https://www.fifa.com/worldcup/groups/'
r = str(requests.get(url).content, 'utf-8')
ret = {}
bs_obj = bs(r,'html.parser')
table_list = bs_obj.findAll('table', {'class':"fi-table fi-standings"})
# print((list(table)[1]))
for table in table_list:
	group_name = table.findAll('p',{"class":"fi-table__caption__title fi-ltr--force"})[0].get_text()[-1]
	Team_list = table.findAll('span',{"class":"fi-t__nText "})
	
	for i in range(4):
		team_text = Team_list[i].get_text()
		team_num = i
#		name, end = "\t")
#		print(team_text, end = "\t ")
#		print(team_num)
		teamid = group_name + str(i)
		ret.update({team_text:teamid})

m = json.dumps(ret)
with open('knockout_country_id.json','w') as f:
	f.write(m)
