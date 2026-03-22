def solution(s):
    answer = ''
    
    blank = True
    for ch in s:
        if ch == ' ':
            blank = True
            answer += ' '
        elif blank:
            if not ch.isdigit():
                answer += ch.upper()
            else:
                answer += ch
            blank = False
        else:
            answer += ch.lower()
    
    return answer