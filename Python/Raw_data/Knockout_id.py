import requests
from bs4 import BeautifulSoup as bs 


url = 'https://www.fifa.com/worldcup/groups/'
r = str(requests.get(url).content, 'utf-8')
bs_obj = bs(r,'html.parser')
table_list = bs_obj.findAll('table', {'class':"fi-table fi-standings"})
# print((list(table)[1]))
for table in table_list:
	group_name = table.findAll('p',{"class":"fi-table__caption__title fi-ltr--force"})[0].get_text()[-1]
	Team_list = table.findAll('span',{"class":"fi-t__nText "})
	print(Team_list[0])
	print(Team_list[1])