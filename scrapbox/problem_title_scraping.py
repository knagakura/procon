import requests
from bs4 import BeautifulSoup

def get_title(contest_num, problem_num):
    r = requests.get("https://atcoder.jp/contests/abc{}/tasks/abc{}_{}".format(contest_num,contest_num,problem_num))
    soup = BeautifulSoup(r.text, 'lxml') #要素を抽出

    print(soup)
    title = str(soup.find("title"))[7:-8]
    return title

l = ["a","b","c","d","e","f"]


for x in l:
    print(get_title(152,x))
