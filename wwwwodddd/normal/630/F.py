n = input()
z = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120
z += n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) / 120 / 6
z += n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) / 120 / 42
print z