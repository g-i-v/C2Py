k=0
i=0
x = []
m=10
for i in range(0,5):
		x.append(int(input()))
for i in range(0,5):
		print(x[i])
if x[2]>7:
	k=1234
elif x[2]<=7:
	k=5678
k=k+m
print(k)
