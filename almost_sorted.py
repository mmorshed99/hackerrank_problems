# https://www.hackerrank.com/challenges/almost-sorted/problem

def merge(arr):
    if len(arr) == 1:
        return arr
    if len(arr) == 2:
        if arr[1] < arr[0]:
            arr[0],arr[1]=arr[1],arr[0]
        return arr
    arr_lft = merge(arr[0:len(arr)//2])
    arr_rgt = merge(arr[len(arr)//2:len(arr)])
    temp = []
    i = 0
    j = 0
    while(i < len(arr_lft) or j< len(arr_rgt)):
            if j < len(arr_rgt) and i < len(arr_lft):
               if arr_lft[i] < arr_rgt[j]:
                   temp.append(arr_lft[i])
                   i +=1
               else:
                    temp.append(arr_rgt[j])
                    j += 1
            elif j < len(arr_rgt):
                temp.extend(arr_rgt[j:len(arr_rgt)])
                j = len(arr_rgt)
            elif  i < len(arr_lft):   
                temp.extend(arr_lft[i:len(arr_lft)])
                i = len(arr_lft)
    return temp            
n = input()
n = int(n)
arr = input().strip().split()
j = 0
arr_save = []
for i in arr:
    arr[j] = int(i)
    arr_save.append(arr[j])
    j += 1

arr_out = merge(arr)

save_idx = []
for i in range(0,n):
    if arr_save[i] != arr_out[i]:
        save_idx.append(i)    
if len(save_idx) == 0:
    print("yes")
elif len(save_idx) == 2:
    foo1 = save_idx[0] + 1
    foo2 = save_idx[1] + 1
    print('yes')
    print("swap " + str(foo1) + " " + str(foo2))
else:
    sub_array = []
    j = save_idx[len(save_idx)-1]
    for i in range(0,save_idx[-1]+1):
       sub_array.append(arr_save[j])
       j = j -1
    j = 0
    for i in range(0,n):
        if i >= save_idx[0] and i<= save_idx[-1]:
            arr_save[i] = sub_array[j]
            j = j + 1
    my_set = 1
    for i in range(0,n):
        if arr_save[i] != arr_out[i]:
            print("no")
            my_set = 0
            break
    if my_set:
        foo1 = save_idx[0] + 1
        foo2 = save_idx[-1] + 1
        print('yes')
        print("reverse " + str(foo1) + " " + str(foo2))
