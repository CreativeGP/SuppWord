#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import time
sys.setrecursionlimit(10000)

def contains(a_list, item):
    first = 0
    last = len(a_list) - 1

    while first <= last:
        i = (first + last) // 2

        if a_list[i] == item:
            return True
        elif a_list[i] > item:
            last = i - 1
        elif a_list[i] < item:
            first = i + 1
        else:
            return False


class Memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
            #Warning: You may wish to do a deepcopy here if returning objects
        return self.memo[args]

@Memoize
def is_supp(s):
    l = len(s)
    res = 0 if contains(dic[l], s) else 1

    if LOG:
        if res == 0:
            print("✔　"+s)
        else:
            print("✗ "+s)

    if l == 2:
        return res 
    else:
#        if res == 1: return 1
        return res + is_supp(s[0:l-1]) + is_supp(s[1:l])

dic = []
LOG = False

# load dictionary
for i in [0,1,2,3,4,5,6,7,8,9]:
    try:
        with open("h"+str(i)) as f:
            con = f.read()
            dic.append(sorted(con.split("\n")))
    except OSError:
        dic.append([])

# target = 'わんだあどりいむ'
for target in dic[7]:
    if is_supp(target) == 2: print(target)
#    print("\n\n")
