def check(w, h, y):
    w -= 2
    h -= 2
    return w*h == y

def solution(brown, yellow):
    
    #brwon+yellow의 약수들 구하기
    #구한 약수 ex) 4, 3에서 둘다 -2 한 값 구하기 ex) 2, 1
    # 두 수를 곱해서 yellow 값과 일치하는지 확인 -> 일치한다면 그 값이 가로 세로
    #max값이 가로임
    
    answer = []
    area = brown+yellow
    
    for i in range(2, area):
        if area%i == 0:
            width, height = i, area//i
            if check(width, height, yellow):
                return max(width, height), min(width, height)
            