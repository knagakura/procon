from numpy.lib.shape_base import dstack
import pandas as pd
from tabulate import tabulate
import datetime
d = pd.read_html("https://www.hallab.co.jp/progcon/2020/ranking/")
d = d[0];
diff = ["NA"];
for i in range(len(d[4]) - 2):
    difff = int(d[4][i+2])-int(d[4][i+1])
    diff.append(difff)

d.columns = d.iloc[0]
d = d.drop(d.index[0])
d["Diff"] = diff;
d = d.set_index("順位")
dt_now = datetime.datetime.now();
dt_str = dt_now.strftime('%Y%m_%H:%M')


d.to_csv("./data/{}.csv".format(dt_str))

print(tabulate(d, headers='keys', tablefmt='psql'))
