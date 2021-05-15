import time

print(time.time())
# ! time.time() returns the number of seconds passes since epoch(reference point) for example in UNIX system 1 January, 1970 00:00 UTC is epoch (the point where time begins).

print(time.localtime())

localtime = time.asctime(time.localtime(time.time()))

print(localtime)
