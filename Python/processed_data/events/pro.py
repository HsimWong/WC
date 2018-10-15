#coding = utf-8
import json

# for i in range(64):
def a():
	i = 0
	with open(str(i) + '.json', 'r') as f:
		st = f.read()
	f.close()
	print('opened')
	print(type(st))
	print(len(st))
	ind = 0
	m = 0
	while (ind < len(st)) & (ind >= 0):
		# print(i)
		pre = ind
		ind = st[pre:].find("],")
		print(ind)
		if ind > len(st):
			break;
		else:
			st = st[0:ind] + '\n\t' + st[ind:]
		m +=1

	print(st)
	# with open(str(i) + '.json', 'w') as f:
	# 	f.write(st)


a()