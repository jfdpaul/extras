import string
import re
from HTMLParser import HTMLParser
import requests
from bs4 import BeautifulSoup
import xlsxwriter

# Create a workbook and add a worksheet.
workbook = xlsxwriter.Workbook('Scholar.xlsx')
worksheet = workbook.add_worksheet()

url= "https://scholar.google.co.in"
h = HTMLParser()
row=0

def iterate(para):
    global row
    para=para.replace(u"\\x3d",u"=")
    para=para.replace(u"\\x26",u"&")
    r = requests.get(url+str(para))
    soup = BeautifulSoup(r.content,"html.parser")

    falcultyLink = soup.find_all("h3", {"class": "gsc_1usr_name"})
    for link in falcultyLink:
        profile = link.find("a")
        para2=profile["href"]
        r2=requests.get(url+str(para2))
        soup2=BeautifulSoup(r2.content,"html.parser")
        facultyName=soup2.find("div", {"id": "gsc_prf_in"})
        #print facultyName.text
        facultyDesg=soup2.find("div", {"class": "gsc_prf_il"})
        #print facultyDesg.text
        nos=soup2.find_all("td", {"class": "gsc_rsb_std"})
        count =0
        citeAll=0
        cite5=0
        hAll=0
        h5=0
        #print nos
        citeAll=nos[0]
        cite5=nos[1]
        hAll=nos[2]
        h5=nos[3]

        #print str(citeAll.text)+str(" ")+str(cite5.text)+str(" ")+str(hAll.text)+str(" ")+str(h5.text)
        worksheet.write(row, 0,str(facultyName.text))
        worksheet.write(row, 1,str(facultyDesg.text))
        worksheet.write(row, 2,str(citeAll.text))
        worksheet.write(row, 3,str(cite5.text))
        worksheet.write(row, 4,str(hAll.text))
        worksheet.write(row, 5,str(h5.text))
        row=row+1

    '''GOTO NEXT PAGE'''
    print row
    button = soup.find("button", {"class": "gs_btnPR gs_in_ib gs_btn_half gs_btn_srt"})
    if button is not None:
        link=button['onclick']
        link=link[17:-1]
        iterate(link)
    else:
        print "------------END----------"

'''
    for a,b in zip(falcultyNames,aff):
        print a.text
        print b.text
'''

para= "/citations?view_op=view_org&hl=en&org=12738307813736707776"
iterate(h.unescape(para))
workbook.close()
