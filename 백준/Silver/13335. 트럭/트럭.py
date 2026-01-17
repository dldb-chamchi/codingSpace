from collections import deque

N, W, L = map(int, input().split())

trucks = deque(map(int, input().split()))

bridge = deque(0 for _ in range(W))

time = 0
num = 0

while num != N:
    bridge.popleft()
    if sum(bridge) + trucks[num] > L:
        bridge.append(0)
    else:
        bridge.append(trucks[num])
        num += 1 
    time += 1

while bridge:
    bridge.pop()
    time += 1

print(time)