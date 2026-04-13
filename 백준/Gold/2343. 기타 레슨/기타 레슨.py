N, M = map(int, input().split())
videos = list(map(int, input().split()))

st = max(videos)
end = sum(videos)

while st <= end:
  mid = (st+end)//2

  sums, cnt = 0, 1
  for v in videos:
    if sums+v > mid:
      sums = 0
      cnt += 1
    sums += v
  
  if cnt > M: #video크기가 크다는 뜻
    st = mid+1
  else:
    ans = mid
    end = mid-1

print(ans)