from urllib import request
from bs4 import BeautifulSoup as bs

wiki = "https://en.wikipedia.org/wiki/2018_FIFA_World_Cup#Tiebreakers"
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}
page = request.Request(wiki, headers = headers)
page_info = request.urlopen(page).read().decode('utf-8')
soup = bs(page_info, 'html.parser')
hhlist = soup.find_all("")