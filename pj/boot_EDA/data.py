import pandas as pd
import requests as req
from bs4 import BeautifulSoup
import warnings
warnings.filterwarnings('ignore')

#2010~2021년 주식 데이터 크롤링
stock_code={'동화약품':'000020', '대한뉴팜':'054670', '이글벳':'044960',
            '경농':'002100','성보화학':'003080', '명문제약' : '017180', '태양':'053620'}
headers = {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Whale/3.19.166.16 Safari/537.36'}

def code_url(stock_code):
    url = f'https://finance.naver.com/item/sise_day.nhn?code={stock_code}&page={page}'
    return url

for i in stock_code:
    stock_name=i
    df = pd.DataFrame()
    page = 0
    for page in range(29, 325):
        data = req.get(code_url(stock_code[stock_name]), headers=headers)
        soup = BeautifulSoup(data.text, "html.parser")
        data = soup.select("table")
        table = pd.read_html(str(data))
        df = df.append(table[0].dropna())
    df = df.sort_values(by='날짜')
    df.to_csv(f"{stock_name}.csv", encoding="utf-8-sig",index=False)
