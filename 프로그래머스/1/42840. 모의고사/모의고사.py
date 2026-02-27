def solution(answers):
    answer = []
    
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    cnt1, cnt2, cnt3 = 0, 0, 0
    
    i = 0
    for num in answers:
        if one[i%5] == num:
            cnt1 += 1
        if two[i%8] == num:
            cnt2 += 1
        if three[i%10] == num:
            cnt3 += 1
        i += 1
    
    maxs = max(cnt1, cnt2, cnt3)
    print(maxs)
    
    if cnt1 == maxs:
        answer.append(1)
    if cnt2 == maxs:
        answer.append(2)
    if cnt3 == maxs:
        answer.append(3)
    
    return answer