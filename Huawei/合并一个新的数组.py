



subLen = int(input())
n = int(input())

lista = [input().split(',') for i in range(n)]

def getResult():
	res = []
	while len(lista) > 0:
		lst = lista.pop(0)
		temp = lst[:subLen]

		del lst[:subLen]
		res.extend(temp)
		if(len(lst)>0):
			lista.append(temp)

	return ",".join(res)

print(getResult())

