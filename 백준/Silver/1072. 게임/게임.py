X, Y = map(int, input().split())

Z = (100*Y)//X 

st = 0; end = X

ans = -1
while st <= end:
    mid = (st+end)//2
    if (100*(Y+mid))//(X+mid) > Z:
        ans = mid
        end = mid-1
    else:
        st = mid+1

print(ans)