# https://www.codewars.com/kata/525f3eda17c7cd9f9e000b39

inside = 0

def wip(num, arg):
	global inside
	if arg == None:
		inside = num
		return None
	
	if arg == 0: return num + inside
	if arg == 1: return num - inside
	if arg == 2: return num * inside
	if arg == 3: return int(num / inside)

def plus(foo)		: return 0
def minus(foo) 		: return 1
def times(foo) 		: return 2
def divided_by(foo) 	: return 3

def zero (arg=None)	: return wip(0, arg)
def one  (arg=None)	: return wip(1, arg)
def two  (arg=None)	: return wip(2, arg)
def three(arg=None)	: return wip(3, arg)
def four (arg=None)	: return wip(4, arg)
def five (arg=None)	: return wip(5, arg)
def six  (arg=None)	: return wip(6, arg)
def seven(arg=None)	: return wip(7, arg)
def eight(arg=None)	: return wip(8, arg)
def nine (arg=None)	: return wip(9, arg)
def ten  (arg=None)	: return wip(10,arg)