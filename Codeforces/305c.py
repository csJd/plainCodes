n = input()
a = map(int, raw_input().split())
s = {}
for i in a :
	j = i
	while j in s :
		del s[j]	
		j = j + 1
	s[j] = 1
print max(s) + 1 - len(s)
