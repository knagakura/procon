
import subprocess
import random
import os
import pandas as pd


exp_name = input()
subprocess.run("g++ -std=c++14 -Wall -Werror -Wshadow -Wno-error=sign-compare -fno-asm -fno-exceptions -DLOCAL -MMD -O3 -DDEBUG Combine.cpp", shell = True)

os.makedirs("exp/{}/".format(exp_name), exist_ok=False)


with open("exp/seed.txt") as f:
    seeds = f.readlines()
    for i in range(len(seeds)):
        seed_dir = "exp/{}/{}/".format(exp_name, "seed{}".format(str(i)))
        os.makedirs(seed_dir)

        tmpout = "{}/{}".format(seed_dir, "tmpout.txt")
        seeds[i] = seeds[i].rstrip()
        command = "./a.out -r {} -e {} > {}".format(seeds[i], exp_name, tmpout)
        print(command);
        subprocess.run(command, shell = True)
        json_name = "{}/{}".format(seed_dir, "result.json")
        result_csv = "{}/{}".format(seed_dir, "result.csv")
        with open(tmpout) as out:
            json_file = open(json_name, "w+")
            outlines = out.readlines()
            json_file.write(outlines[0])

            result_file = open(result_csv, "w+")
            for i in range(1, len(outlines)):
                result_file.write(outlines[i])
    for i in range(len(seeds)):
        seed_dir = "exp/{}/{}/".format(exp_name, "seed{}".format(str(i)))
        result_csv = "{}/{}".format(seed_dir, "result.csv")
        df = pd.read_csv(result_csv, sep = ",", comment="#", header=0)
        print(df)