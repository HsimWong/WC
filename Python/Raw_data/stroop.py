from urllib.request import urlopen
from bs4 import BeautifulSoup
import threading
import time
import requests
from urllib.request import urlretrieve
import re
import json
import sys
import string
import os
import socket
import urllib

base_url="https://m.weibo.cn/api/container/getIndex?containerid=2304132331498495_-_WEIBO_SECOND_PROFILE_WEIBO&luicode=10000011&lfid=2302832331498495&featurecode=20000320&page_type=03&page={}"#半藏森林

socket.getdefaulttimeout=30
pics_dir='D:/pics_origin/'

def get_text(card):
    try:
        text=card['mblog']['text']
    except:
         return None
    else:
        if '<' in text:
            text=re.findall(r'(.+?)<',text)[0]#偷懒只取了微博内容的前半部分
        text=re.sub(':','：',text)
        text=text.strip()
        return text

def get_cards(page):
    url=base_url.format(page)
    html=requests.get(url)
    r=html.json()
    cards=r['data']['cards']
    print(len(cards))
    return cards

def save_pics(pics_info,text):
    i=0
    for pic_info in pics_info:
        pic_url=pic_info['large']['url']#原图
        #pic_url=pic_info['url']#低清图
        pic_path=pics_dir+text+'_%d.jpg'%i
        if os.path.exists(pics_dir+text+'_%d.jpg'%i):
            print(pics_dir+text+'_%d.jpg已存在'%i)
            i+=1
            continue
        try:
            #下载图片
            with open(pic_path,'wb') as f:
                for chunk in requests.get(pic_url,stream=True).iter_content():
                    f.write(chunk)
                    #urlretrieve(pic_url,pics_dir+text+'_%d.jpg'%i)

        #except socket.timeout:
        #    print(text+'_%d保存失败'%i)
        #except urllib.error.ContentTooShortError:
        #    urlretrieve(pic_url,pics_dir+text+'_%d.jpg'%i)
        except:
            print(text+'_%d保存失败'%i)
        else:
            print(text+'_%d保存成功'%i)
            i+=1


def check_dir():
    if not os.path.exists(pics_dir):
        os.mkdir(pics_dir)


class MyThread(threading.Thread):
    def __init__(self,pics_info,text):
        threading.Thread.__init__(self)
        self.pics_info=pics_info
        self.text=text

    def run(self):
        save_pics(self.pics_info,self.text)

check_dir()
page=1
while True:
    cards=get_cards(page)
    if len(cards)>1:
        threads=[]
        for card in cards:
            #下载每个card里面的图片
            text=get_text(card)
            try:
                pics_info=card['mblog']['pics']
            except:
                pass
            else:
                #save_pics(pics_info)
                thread=MyThread(pics_info,text)
                threads.append(thread)
                thread.start()
        for thread in threads:
            thread.join()
        page+=1
        time.sleep(1)
    else:
        break

