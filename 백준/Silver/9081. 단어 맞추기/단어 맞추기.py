def next_permunations():
  i = len(arr)-2
  while i >= 0 and arr[i] >= arr[i+1]:
    i -= 1
  pivot = i

  if pivot < 0:
    return None
  
  j = len(arr)-1
  while j > pivot and arr[j] <= arr[pivot]:
    j -= 1
  
  arr[pivot], arr[j] = arr[j], arr[pivot]

  arr[pivot+1:] = reversed(arr[pivot+1:])

  return arr

for _ in range(int(input())):
  string = input()
  arr = list(string)
  value = next_permunations()

  if value == None:
    print(string)
  else:
    print(''.join(arr))