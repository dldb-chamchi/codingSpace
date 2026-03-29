def solution(x, y):
    a = min(x, y)
    b = max(x, y)
    return ((b*(b+1)/2) - (a*(a+1)/2)) + a