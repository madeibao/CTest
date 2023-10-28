


# coding:utf-8
#JSRUN引擎2.0，支持多达30种语言在线运行，全仿真在线交互输入输出。 
import functools
import sys
from collections import Counter, defaultdict
import copy
from itertools import permutations
import re
import math
import sys
 
str1 = input()
str2 = input()
str2 = re.sub(r'\[(.*?)\]', r'[\1]', str2)
pattern = re.compile(str2)
if pattern.search(str1) is None:
    print(-1)
else:
    print(pattern.search(str1).start())

    