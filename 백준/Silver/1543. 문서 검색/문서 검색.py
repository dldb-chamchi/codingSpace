#백준 1543, 문서 검색

string = list(input())
word = list(input())

idx = 0
cnt = 0
while idx < len(string):
    length = 0
    tmpIdx = idx
    for c in word:
        if tmpIdx >= len(string):
            idx += 1
            break
        if c != string[tmpIdx]:
            idx += 1
            break
        if c == string[tmpIdx]:
            length += 1
        if length == len(word):
            cnt += 1
            idx = tmpIdx+1
        tmpIdx += 1

print(cnt)