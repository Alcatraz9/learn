def solve(arr):
    res = curr = 1

    for i in range(1, len(arr)):
        if arr[i] <= arr[i-1]:
            curr = 1
        else:
            curr+=1
        
        res += curr
    
    return res


arr = list(input().split(' '))
print(solve(arr))