# -*- coding: utf-8 -*- 
import openpyxl
with open('cup.txt', 'r') as f:
	lines = f.readlines()
	
for line in lines:
	if not (line.find("@", beg = 0, end = len(line))) == -1:
