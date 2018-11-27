# coding = 'utf-8'

a = ""

def SetString(string):
	global a;
	a = string

def getString():
	global a
	return a


if __name__ == '__main__':
	SetString("A Sample");
	print(getString());