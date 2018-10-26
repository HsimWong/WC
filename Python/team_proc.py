# coding = 'utf-8'

import json

with open('processed_data\\team_member_info.json') as f:
	data = json.loads(f.read())

data_new = {value:key for key,value in data.items()}

group = 