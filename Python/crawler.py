# -*- coding: UTF-8 -*-
import requests



if __name__ == "__main__":
	url = '''https://www.fifa.com/CompiledAssets/js/modules/matchlist.js?_t=ba7acb9937ecf6187fca8a718c2adbfe'''
	with open('a.html','w') as f:
		f.write(requests.get(url).text)