#백준, 14916 거스름돈

N = int(input())

mul = 1
maxMul = 0
while True:
    if 5*mul > N:
        break
    if (N-5*mul) % 2 == 0:
        maxMul = mul
    mul+= 1

if maxMul > 0:
    print(maxMul+(N-5*maxMul)//2)
elif N%2 == 0:
    print(N//2)
else:
    print(-1)