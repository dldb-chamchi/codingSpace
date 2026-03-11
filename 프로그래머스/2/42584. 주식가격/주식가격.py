from collections import deque

def solution(prices):
    answer = [0]*(len(prices))
    stack = deque()
    
    idx = -1
    for p in prices:
        idx += 1
        if stack:
            if stack[-1][0] <= p: #안 떨어짐
                stack.append((p, idx))
            else: #떨어짐
                while stack:
                    if stack[-1][0] <= p:
                        break
                    else:
                        v, i = stack.pop()
                        answer[i] = idx-i
                        
                stack.append((p, idx))
        else:
            stack.append((p, idx))
            
    while stack:
        v, i = stack.pop()
        answer[i] = idx-i
    
    return answer