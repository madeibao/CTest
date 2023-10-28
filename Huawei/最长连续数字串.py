

import re

s = input()

def getResult(s):
	reg = re.compile(r"([+-]?\d+\.?\d+)")

	match = reg.findall(s)
	match.sort(key=lambda x: len(x))

	return match[-1]

print(getResult(s))