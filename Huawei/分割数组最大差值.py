

import sys

tag = False
count = 0

input_list = []

for line in sys.stdin:
	if not tag:
		tag = True
		count = int(line)
	else:
		input_list = line.split(" ")
		input_list = [int(x) for x in input_list]
		break

input_list = input_list[:count]

def main():
	result = 0
	for x in range(1,len(input_list)):
		a = input_list[:x]
		b = input_list[x:]

		suma = sum(a)
		sumb = sum(b)

		delta = abs(suma-sumb)
		if(delta > result):
			result = delta
	return result

print(main())
