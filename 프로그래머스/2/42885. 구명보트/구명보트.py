def solution(people, limit):
    people.sort()
    left, right = 0, len(people)-1
    
    num = 0
    while left <= right:
        weight = people[left] + people[right]
        if weight > limit:
            right -= 1
        else:
            left += 1
            right -= 1
        num += 1
    return num