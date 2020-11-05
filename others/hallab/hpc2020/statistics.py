import pandas as pd
exp_name = input()
with open("exp/seed.txt") as f:
    seeds = f.readlines()
    for i in range(len(seeds)):
        seed_dir = "exp/{}/{}/".format(exp_name, "seed{}".format(str(i)))
        result_csv = "{}/{}".format(seed_dir, "result.csv")
        df = pd.read_csv(result_csv, sep = ",", comment="#", header=0, index_col = 0)
        print(df)