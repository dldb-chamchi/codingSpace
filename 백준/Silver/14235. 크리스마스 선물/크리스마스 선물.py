from queue import PriorityQueue

que = PriorityQueue()

for i in range(int(input())):
    num = list(map(int, input().split()))
    if num[0] == 0:
        if que.empty():
            print(-1)
        else:
            print(que.get()*-1)
    else:
        for i in range(1, len(num)):
            que.put(num[i]*-1)
