import os

pid1 = os.fork()

if pid1 == 0:
    
    print("je suis le fils 1")
else:
    pid2 = os.fork()

    if pid2 == 0:
        
        print("je suis le fils 2")
    else:
        
        print("je suis le père")