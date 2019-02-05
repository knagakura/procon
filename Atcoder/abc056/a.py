a, b = map(str,input().split())
if a == "H" and b == "H":
	ans = "H"
elif a =="H" and b == "D":
	ans = "D"
elif a == "D" and b =="H":
	ans = "D"
elif a =="D" and b =="D":
	ans = "H"
print(ans)