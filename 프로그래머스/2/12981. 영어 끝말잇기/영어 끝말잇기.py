def solution(n, words):
    
    used = []
    compare = words[0][0]
    
    num, turn = 1, 1
    for word in words:
        if compare != word[0] or word in used:
            return [n, turn] if num%n == 0 else [num%n, turn]
        compare = word[-1]
        if num % n == 0: #턴 한번 지남
            turn += 1
        num += 1
        used.append(word)
    return [0, 0]