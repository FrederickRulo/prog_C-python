import os
import time
import random

start = time.time()  

pid1 = os.fork()
if pid1 == 0:
    t = random.randint(1, 10)
    print(f"fils 1 : je vais dormir {t} secondes")
    time.sleep(t)
    print("fils 1 terminé")
    exit(0)
else:
    pid2 = os.fork()
    if pid2 == 0:
        t = random.randint(1, 10)
        print(f"fils 2 : je vais dormir {t} secondes")
        time.sleep(t)
        print("fils 2 terminé")
        exit(0)
    else:
        os.wait()  
        os.wait() 
        end = time.time()
        print(f"Durée totale : {int(end - start)} secondes")
