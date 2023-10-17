


import itertools

# string = "aabbbccccddddeeeee"  

string = input()
max_consecutive_count = max(len(list(g)) for k, g in itertools.groupby(string))  
print(max_consecutive_count)