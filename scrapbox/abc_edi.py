import datetime
import urllib.request
import webbrowser
import requests
from bs4 import BeautifulSoup
print("ABC{}_{}")
###プロジェクトURL###
project_url='longshoujin'

def get_title(contest_num, problem_num):
    r = requests.get("https://atcoder.jp/contests/abc{}/tasks/abc{}_{}".format(contest_num,contest_num,problem_num))
    soup = BeautifulSoup(r.text, 'lxml') #要素を抽出
    title = str(soup.find("title"))[7:-8]
    return title

now=datetime.datetime.today()   #当日の日付を取得

contest_num, problem_num = input().split()
problem_title = get_title(contest_num, problem_num)
title = "AtCoder Begginer Contest ABC{} {}".format(contest_num, problem_title)

#contents
tag = "　#ABC"
problem_url = "　[{} https://atcoder.jp/contests/abc{}/tasks/abc{}_{}]".format(problem_title, contest_num, contest_num, problem_num)
seiyaku = "　制約\n [$ 1\leq N\leq 10^{5}] "

#まとめる
contents_list = [tag, problem_url, seiyaku,"code:cpp"]
contents = '\n'.join(contents_list)

contents_encode=urllib.parse.quote(contents)
print(contents)
###ページのレイアウト###
#'?body='より後ろの3つの変数は、
#左から順に、〈当月・前日・翌日へのリンク〉→〈改行2回〉→〈本文に自動で記入する文字列〉
#改行したいところはurllib.parse.quote('\n')と書く。
url = 'https://scrapbox.io/' + project_url + '/' + title + '?body=' + contents
print(url)
webbrowser.open(url)