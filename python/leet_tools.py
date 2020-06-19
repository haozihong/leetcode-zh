def print_line(a):
    for l in a:
        for ch in l:
            print("{:2}".format(ch),end = ",")
        print()

def timeit(fn, ins):
    from time import time
    from leet_binary_tree import stringToTreeNode

    tt = 5
    s = time()
    for i in range(tt):
        ou = fn(stringToTreeNode(*ins))
    print(ou)
    print("1:", time() - s)