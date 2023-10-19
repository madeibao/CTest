


#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created with IntelliJ IDEA.
File: main0260.py
Author: Amos
E-mail: amos@amoscloud.com
Date: 2023/8/16
Time: 14:04
Description:
"""
def count_right_triangles(N, segments):
    segments.sort()
    count = 0
    used = set()

    for i in range(N):
        for j in range(i + 1, N):
            for k in range(j + 1, N):
                a, b, c = segments[i], segments[j], segments[k]

                if (a, b, c) in used:
                    continue

                if a * a + b * b == c * c:
                    count += 1
                    used.add((a, b, c))

    return count


T = int(input())
for _ in range(T):
    data = list(map(int, input().split()))
    N = data[0]
    segments = data[1:]
    print(count_right_triangles(N, segments))