i=1
k=1
s=k%3
print(s)
i=2
k=5
s=k%3
print(s)
i=3
k=9
s=k//3
print(s)
i=4
k=13
s=k//3
print(s)

def aladin(book_title, book_author):
    try:
        chrome.get(“https://www.aladin.co.kr/home/welcome.aspx”)
        time.sleep(2)
        # chrome.maximize_window # 창을 최대 크기로 키우기
        chrome.find_element(By.ID, ‘SearchWord’).click()
        search = chrome.find_element(By.ID, ‘SearchWord’)
        search.send_keys(book_title, book_author)
        time.sleep(1)
        # search.send_keys(“\n”)
        chrome.find_element(By.CLASS_NAME, ‘searchBtn’).click()
        time.sleep(3)
        dis = chrome.find_element(By.CSS_SELECTOR, ‘table > tbody > tr:nth-child(1) > td:nth-child(1) > div:nth-child(1) > ul > li:nth-child(3) > span:nth-child(3)’).text
        chrome.find_element(By.CLASS_NAME, ‘bo3’).click()
        titles = chrome.find_element(By.CSS_SELECTOR, ‘div > ul > li:nth-child(2) > div > a.Ere_bo_title’).text
        prices = chrome.find_element(By.CSS_SELECTOR, ‘ul > li:nth-child(2) > div.Ritem.Ere_ht11 > span’).text
        author = chrome.find_element(By.CSS_SELECTOR, ‘div > ul > li.Ere_sub2_title > a:nth-child(1)‘).text
        time.sleep(3)
        return [‘알라딘‘, titles, author, prices+‘원’+ ' (' +dis+' 할인' + ‘)’]
    except:
        return [‘알라딘‘, ‘잘못 입력하셨습니다‘, ‘’, ‘’]