from itertools import permutations

def check(n):
    if n < 2:
        return False
    
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

def solution(numbers):
    nums = set()
    
    for l in range(1, len(numbers)+1):
        for p in permutations(numbers, l):
            nums.add(int(''.join(p)))
            
    answer = 0
    
    for n in nums:
        if check(n):
            answer += 1
        
    return answer