import pandas as pd
import requests as req
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings('ignore')

########### 2010~2021년 주식 데이터 크롤링 : 데이터가 없는 처음만 실행(속도 문제)
stock_code={'동화약품':'000020', '대한뉴팜':'054670', '이글벳':'044960', '경농':'002100','성보화학':'003080', '명문제약' : '017180', '태양':'053620'}
"""
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

tem_df = pd.read_csv("winter_temp.csv")
"""
########################################
tem_df = pd.read_csv("winter_temp.csv")

stock=list(stock_code)

def subyear(name):#1월~12월
    df=pd.read_csv(f"{name}.csv")
    df_2010 = df.iloc[0:249]
    df_2011 = df.iloc[249:497]
    df_2012 = df.iloc[497:745]
    df_2013 = df.iloc[745:992]
    df_2014 = df.iloc[992:1237]
    df_2015 = df.iloc[1237:1485]
    df_2016 = df.iloc[1485:1731]
    df_2017 = df.iloc[1731:1974]
    df_2018 = df.iloc[1974:2218]
    df_2019 = df.iloc[2218:2464]
    df_2020 = df.iloc[2464:2712]
    df_2021 = df.iloc[2712:2960]
    ystock=[df_2010, df_2011, df_2012, df_2013, df_2014, df_2015,
            df_2016, df_2017, df_2018, df_2019, df_2020, df_2021]
    def diff_year(df):
        #year=re.sub(r'[^0-9]', '', year)
        max=df["종가"].max()
        min=df["종가"].min()
        diff= max - min
        return diff
    diff=[]
    for i in ystock:
        diff.append(diff_year(i))
    return diff
def subyear2(name):#2월~8월
    df=pd.read_csv(f"{name}.csv")
    df_2010 = df.iloc[19:164]
    df_2011 = df.iloc[269:413]
    df_2012 = df.iloc[516:663]
    df_2013 = df.iloc[766:911]
    df_2014 = df.iloc[1011:1155]
    df_2015 = df.iloc[1257:1401]
    df_2016 = df.iloc[1504:1648]
    df_2017 = df.iloc[1750:1895]
    df_2018 = df.iloc[1995:2138]
    df_2019 = df.iloc[2239:2381]
    df_2020 = df.iloc[2483:2629]
    df_2021 = df.iloc[2731:2877]
    ystock=[df_2010, df_2011, df_2012, df_2013, df_2014, df_2015, df_2016, df_2017, df_2018, df_2019, df_2020, df_2021]
    def diff_year(df):
        #year=re.sub(r'[^0-9]', '', year)
        max=df["종가"].max()
        min=df["종가"].min()
        diff= max - min
        return diff
    diff=[]
    for i in ystock:
        diff.append(diff_year(i))
    return diff

plt.figure(figsize=(10, 10))
plt.title('℃-diff')

plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[0]), c='red')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[1]), c='orange')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[2]), c='yellow')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[3]), c='green')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[4]), c='blue')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[5]), c='purple')
plt.scatter(tem_df['평균기온(℃)'], subyear2(stock[6]), c='navy')

plt.grid(color='gray', linestyle='--')
plt.show()