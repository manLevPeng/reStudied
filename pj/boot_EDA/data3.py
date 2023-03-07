import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import dates as mdates
import seaborn as sns
import warnings
warnings.filterwarnings('ignore')

stock_code={'동화약품':'000020', '대한뉴팜':'054670', '이글벳':'044960', '경농':'002100','성보화학':'003080', '명문제약' : '017180', '태양':'053620'}
stock=list(stock_code)

def subyear2(name):  #2월~8월
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
    print(df_2021.head())
    print(df_2021.tail())
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

subyear2(stock[0])
