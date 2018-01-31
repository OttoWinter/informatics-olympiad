N = 100
T = sum([x for x in range(1, N + 1)])
print(T)
for x in range(1, N + 1):
    for y in range(1, x + 1):
        print(f"{x} {y}")
