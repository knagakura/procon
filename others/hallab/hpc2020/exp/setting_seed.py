
import random

f = open("seed.txt", "w")
for _ in range(10):
    seeds = "{} {} {} {}\n".format(random.randint(1,100),random.randint(1,100), random.randint(1,100), random.randint(1,100))
    f.write(seeds)