#백준, 9996 한국이 그리울 땐 서버에 접속하지

N = int(input())
pattern = input()

for i in range(N):
    endFlag = False
    string = input()
    for idx1 in range(len(pattern)):
        if pattern[idx1] == '*':
            break
        if idx1 >= len(string) or pattern[idx1] != string[idx1]:
            endFlag = True
            break
    
    pattern2 = pattern[idx1+1:]
    
    if len(string) < len(pattern2):
        endFlag = True
    else:
        for idx2 in range(len(pattern2)):
            if idx1-1 >= len(string)-idx2-1:
                endFlag = True
            if pattern2[len(pattern2)-idx2-1] != string[len(string)-idx2-1]:
                endFlag = True
        
    print("NE" if endFlag else "DA")
         