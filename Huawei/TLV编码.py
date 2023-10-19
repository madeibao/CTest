#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created with IntelliJ IDEA.
File: main0003
Author: Amos
E-mail: amos@amoscloud.com
Date: 2023/2/8
Time: 20:55
Description:
"""

aim_tag = input()
data = input().split()

p = 0
while p < len(data):
    tag = data[p]
    len_hex = int(data[p + 2] + data[p + 1], 16)
    value = ' '.join(data[p + 3:p + 3 + len_hex])
    if tag == aim_tag:
        print(value)
    p += 3 + len_hex