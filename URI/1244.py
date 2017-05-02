cases = int(input())

for case in range(cases):
	s = [x for x in input().split()]
	d = {}

	for st in s:

		if d.get(len(st)) != None:
			d[len(st)].append(st)
		else:
			d[len(st)] = [st]

	lis = list(d.keys())
	lis.sort()
	lis.reverse()
	s = []
	for k in lis:
		for l in d[k]:
			s.append(str(l))
	print(" ".join(s))
	
