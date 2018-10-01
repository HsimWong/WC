# 给每个球队编码

import json 


with open('groups.json','r') as f:
	data = f.read()
new_dict = json.loads(data)

js = {}
print(new_dict['name'])
for group in new_dict['groups']:
	new_group = {}
	group_name = str(group['name'])
	group_name = group_name[len(group_name) - 1]
	# print(group_name)
	for i in range(len(group['teams'])):
		group['teams'][i].update({'index':i})
		# group[]
		ind = group_name + str(i)
		js.update({group['teams'][i]['name']:ind})
		# print(group['teams'][i]['name'])

with open('country_ind_groupphase.json','w') as f:
	json.dump(js,f)
	print("OK")