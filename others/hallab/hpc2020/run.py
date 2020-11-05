
import subprocess
import random

subprocess.run("g++ -std=c++14 -Wall -Werror -Wshadow -Wno-error=sign-compare -fno-asm -fno-exceptions -DLOCAL -MMD -O3 -DDEBUG Combine.cpp", shell = True)

with open("exp/seed.txt") as f:
    seeds = f.readlines()
    print(seeds)
    for i in range(len(seeds)):
        seeds[i] = seeds[i].rstrip()
        command = "./a.out -r {}".format(seeds[i])
        print(command);
        subprocess.run(command, shell = True)
