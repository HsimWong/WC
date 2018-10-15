import json


with open("event.json",'r') as f:
	data = f.read()

goals = json.loads(data)

for goal in goals:
	match_id = goal
