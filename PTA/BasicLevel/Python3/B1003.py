def check(text: str) -> bool:
    
    pass


n = int(input())
for _ in range(n):
    text = input()
    print("{}".format("YES" if check(text) else "No"))
