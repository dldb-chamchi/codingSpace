from collections import Counter

name = input()
freq = Counter(name)

alphabet = ''
ans = ''
odd = 0
for i in sorted(freq):
    if freq[i] % 2 != 0:
        odd += 1
        alphabet += i
    
    for _ in range(freq[i]//2):
        ans += i

if odd > 1:
    print("I'm Sorry Hansoo")
elif not odd:
    print(''.join([ans, ans[::-1]]))
else:
    print(''.join([ans, alphabet, ans[::-1]]))
