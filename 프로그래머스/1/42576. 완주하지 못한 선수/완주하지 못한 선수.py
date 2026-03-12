def solution(participant, completion):
    
    dic = {}
    
    for i in range(len(participant)):
        if participant[i] in dic:
            dic[participant[i]] += 1
        else:
            dic[participant[i]] = 1
    
    for i in range(len(completion)):
        if completion[i] in dic:
            dic[completion[i]] -= 1
    
    for n, v in dic.items():
        if v == 1:
            return n