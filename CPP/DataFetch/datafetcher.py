import json
import urllib
import requests
import sys, os
def is_valid(match):
	return(
	isinstance(match, dict) and
	isinstance(match.get('home_team'), dict) or
	isinstance(match.get('away_team'), dict))

# def fetch(endpoint):
# 	"""
# 	Fetching matches results
# 	"""
# 	url = ""
endpoint = ''

url = "http://worldcup.sfg.io/matches/%(endpoint)s" % {
        "endpoint": endpoint
    }

data = requests.get(url)
matches = data.json
for match in matches:
	if is_valid(match):
		yield match