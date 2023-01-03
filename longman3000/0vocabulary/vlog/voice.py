

import requests
import os
from bs4 import BeautifulSoup

url =
targetDir = "D:\\music"

html = requests.get(url)
soup = BeautifulSoup(html.text,features='html.parser')

audioName=[]

for audio in soup.find_all('a'):
    ac=audio.get('class')
    if not ac:
        continue
    if ac[0]=='title':
        andioName.append(audio.string)