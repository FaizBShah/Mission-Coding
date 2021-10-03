t = int(input())
for __ in range(t):
	n,m = map(int,input().split())
	r,l = 0,0
	flagl,flagr = 0, 0
	minute = [100001]*n
	a = list(map(int,input().split()))
	for i in range(len(a)):
		if a[i] == 1:
			r = 0
			flagr = 1
			minute[i] = 0
		elif a[i] == 2:
			minute[i] = 0
		elif a[i]==0 and flagr == 1:
			minute[i] = r
		r+=1
	for i in range(len(a)-1,-1,-1):
		if a[i] == 2:
			l = 0
			flagl = 1
		elif a[i] == 0 and flagl == 1:
			minute[i] = min(l,minute[i])
		l+=1
	minute[0] = 0
	# print(minute)
	b = list(map(int,input().split()))
	for i in range(len(b)):
		if minute[b[i]-1] == 100001:
			print(-1,end=" ")
		else:
			print(minute[b[i]-1],end=" ")
	print()
