# varis = [['time','string'],['match_id','int'],['goalerTeamCode','string'],['goaler_id','int'],['ifOG','bool'],['goal_belong','string']]
varis = []
className = input("Please input the class Name\n")
while True:
	temp_type = input('Please input the type of the varible:\n')
	if temp_type == -1:
		break;
	else:
		var_name = input('Please input the name of the variable\n')
	varis.append([var_name,temp_type])

# className = 'Goal'
string = '''#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
'''
string += ('\nclass ' + className + '{\nprivate:')

for var in varis:
	string += '\n\t' + var[1] + ' ' + var[0] +';'
string += '\npublic:'


string += '\n\t' + className + "("
for i in range(len(varis)):
	string += varis[i][1] + ' ' + varis[i][0]
	if not i == (len(varis) - 1):
		string += ', '
string += ');'


for var in varis:
	string += '\n\t' + var[1] + ' get_' + var[0] + '();'
string += '\n};\n\n'+className +'::'+className + '('
for i in range(len(varis)):
	string += varis[i][1] + ' ' + varis[i][0]
	if not i == (len(varis) - 1):
		string += ', '
string += '){'
for var in varis:
	string += '\n\tthis -> ' + var[0] + ' = ' + var[0] + ';'

string+='\n};'


for var in varis:
	string +=  '\n\n' + var[1] + ' ' + className +'::' + 'get_' +var[0] + '(){\n\treturn this -> ' + var[0] + ';\n}'

filename = className +'.cpp'
f = open(filename,'w')
f.write(string)
f.close