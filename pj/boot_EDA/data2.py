import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import dates as mdates
import seaborn as sns
import warnings
warnings.filterwarnings('ignore')

동화df = pd.read_csv("동화약품.csv")
대한뉴팜df = pd.read_csv("대한뉴팜.csv")
이글벳df = pd.read_csv("이글벳.csv")
경농df = pd.read_csv("경농.csv")
성보화학df = pd.read_csv("성보화학.csv")
tem_df = pd.read_csv("winter_temp.csv")

df_2010 = 대한뉴팜df.iloc[0:249]
df_2011 = 대한뉴팜df.iloc[249:497]
df_2012 = 대한뉴팜df.iloc[497:745]
df_2013 = 대한뉴팜df.iloc[745:992]
df_2014 = 동화df.iloc[992:1237]
df_2015 = 동화df.iloc[1237:1485]
df_2016 = 동화df.iloc[1485:1731]
df_2017 = 동화df.iloc[1731:1974]
df_2018 = 동화df.iloc[1974:2218]
df_2019 = 동화df.iloc[2218:2464]
df_2020 = 동화df.iloc[2464:2712]
df_2021 = 동화df.iloc[2712:2960]

fig=plt.figure(figsize=(15, 5))
fig=plt.title('동화제약')
fig=plt.xticks(rotation=45)

ax1 = fig.subplot(4, 3, 1)        #ax=칸
"""ax2 = fig.add_subplot(4,3,2)
ax3 = fig.add_subplot(4,3,3)
ax4 = fig.add_subplot(4,3,4)
ax5 = fig.add_subplot(4,3,5)
ax6 = fig.add_subplot(4,3,6)
ax7 = fig.add_subplot(4,3,7)
ax8 = fig.add_subplot(4,3,8)
ax9 = fig.add_subplot(4,3,9)
ax10 = fig.add_subplot(4,3,10)
ax11= fig.add_subplot(4,3,11)
ax12 = fig.add_subplot(4,3,12)"""
ax1=sns.lineplot(x=df_2010['날짜'], y=df_2010['종가'])
ax1=sns.lineplot(x=df_2011['날짜'], y=df_2011['종가'])
ax1=sns.lineplot(x=df_2012['날짜'], y=df_2012['종가'])
ax1=sns.lineplot(x=df_2013['날짜'], y=df_2013['종가'])
ax1=sns.lineplot(x=df_2014['날짜'], y=df_2014['종가'])
ax1=sns.lineplot(x=df_2015['날짜'], y=df_2015['종가'])
ax1=sns.lineplot(x=df_2016['날짜'], y=df_2016['종가'])
ax1=sns.lineplot(x=df_2017['날짜'], y=df_2017['종가'])
ax1=sns.lineplot(x=df_2018['날짜'], y=df_2018['종가'])
ax1=sns.lineplot(x=df_2019['날짜'], y=df_2019['종가'])
ax1=sns.lineplot(x=df_2020['날짜'], y=df_2020['종가'])
ax1=sns.lineplot(x=df_2021['날짜'], y=df_2021['종가'])
"""sns.lineplot(x=df_2010['날짜'], y=df_2010['종가'], ax=ax1)
sns.lineplot(x=df_2011['날짜'], y=df_2011['종가'], ax=ax2)
sns.lineplot(x=df_2012['날짜'], y=df_2012['종가'], ax=ax3)
sns.lineplot(x=df_2013['날짜'], y=df_2013['종가'], ax=ax4)
sns.lineplot(x=df_2014['날짜'], y=df_2014['종가'], ax=ax5)
sns.lineplot(x=df_2015['날짜'], y=df_2015['종가'], ax=ax6)
sns.lineplot(x=df_2016['날짜'], y=df_2016['종가'], ax=ax7)
sns.lineplot(x=df_2017['날짜'], y=df_2017['종가'], ax=ax8)
sns.lineplot(x=df_2018['날짜'], y=df_2018['종가'], ax=ax9)
sns.lineplot(x=df_2019['날짜'], y=df_2019['종가'], ax=ax10)
sns.lineplot(x=df_2020['날짜'], y=df_2020['종가'], ax=ax11)
sns.lineplot(x=df_2021['날짜'], y=df_2021['종가'], ax=ax12)"""




#plt.grid(color='gray', linestyle='--')
plt.show()
