# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	tot = None
	for i in range(n):
		if a[i] != i:
			if tot is None:
				tot = i
			else:
				tot &= i
	print(tot)