N, L, W, H = map(int, input().split())

st = 0; end = max(max(L, W), H)

for i in range(10000):
  mid = (st+end)/2

  if (L//mid) * (W//mid) * (H//mid) >= N:
    st = mid
  else:
    end = mid
  
print("%.10f" %st)