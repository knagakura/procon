import sys
import os
from urllib import request
from bs4 import BeautifulSoup
import requests

def char_range(c1, c2):
    """Generates the characters from `c1` to `c2`, inclusive."""
    for c in range(ord(c1), ord(c2)+1):
        yield chr(c)

contest_name = os.getcwd().split("/")[-1]
task_name = contest_name
if os.path.isfile(os.getcwd()+"/auto_edi.md"):
    print("すでにファイルが存在します")
    exit()


fo = open("auto_edi.md", 'w')
sys.stdout = fo


print("[:contents]\n")

for problem_name in char_range('a', 'f'):
    contest_url = "https://atcoder.jp/contests/{}/tasks/{}_{}".format(contest_name, task_name, problem_name)
    problem_html = requests.get(contest_url)
    problem_soup = BeautifulSoup(problem_html.content, "html.parser")
    print("### [{}]({})\n".format(problem_soup.title.get_text(), contest_url))
    print("[問題へのリンク]({})\n".format(contest_url))
    print("#### 解説\n")
    print("#### 実装\n")
    print("```cpp\n")
    print("```\n")

