

2 3 4 5


import sys;

list = input().strip().split(' ')
group = []

for i in range(0, len(list)):
	group.append((i,int(list[i])))

def fight(list):
	if(len(list)%2!=0):
		list.append((-1,-1))
	if(len(list)==4):
		if(list[0][1]>=list[1][1]):
			a = list[0]
			b = list[1]
		else:
			a = list[1]
			b = list[0]

		if(list[2][1]>=list[3][1]):
			c = list[2]
			d = list[3]

		else:
			c = list[3]
			d = list[2]


		if(a[1]>=c[1]):
			print(a[0],end=' ')
			print(c[0],end=' ')
		else:
			print(c[0],end=' ')
			print(a[0],end=' ')

		if(b[1]>=d[1]):
			print(b[0],end='')
		else:
			print(d[0],end='')
	else:
		next = []

		for i in range(0,len(list),2):
			if list[i][1]>=list[i+1][1]:
				next.append(list[i])
			else:
				next.append(list[i+1])
		return fight(next)


fight(group)
