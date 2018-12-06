import json
from datetime import *
from webview.DataControl.Overall_func import *

with open('./webview/DataControl/Raw_data/worldcup.json', 'r') as f:
	dic = json.loads(f.read())


times = []
for day in dic['rounds']:
	for game in day['matches']:
		time_str = game['date'] + ' ' + game['time'];
		timezone = int(game['timezone'][-1])
		time = datetime.strptime(time_str,'%Y-%m-%d %H:%M') + timedelta(hours = int(timezone))

		times.append(time)
