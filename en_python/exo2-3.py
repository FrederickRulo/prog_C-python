import os

for i in range(5):
    pid = os.fork()

    if pid == 0:
        print(f"je suis le fils {i+1}")
        break 
