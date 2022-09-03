test_case_str = input()
test_case = int(test_case_str)
result1=[]
for i in range(test_case):
    num_string = input().split()
    num = num_string[0]
    result=[]
    str_list = list(num_string[1])
    for j in str_list:
        result.append(j*int(num))
    result1.append("".join(result))
for k in range(len(result1)):
    print(result1[k])

        
