#coding = utf-8
import json

for i in range(64):
	with open(str(i) + '.json') as f:
		st = f.read()
	f.close()
	goals = json.loads(st)
	output_str = "[\n\t"
	for goal in goals:
		output_str += str(goal) + ',\n\t'

	output_str += ']'

	with open(str(i) + '.json') as f:
		f.write(output_str)


