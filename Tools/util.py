# -*- coding: utf-8 -*-
import base64
import cv2
import numpy as np
import requests
import json
import os
import sys
sys.path.append("../")
from OCR_Project import ReadExcel, DrawFeatures

def base64_cv2(base64_encode):
    base64_decode = base64.b64decode(base64_encode)
    nparr = np.fromstring(base64_decode, np.uint8)
    return cv2.imdecode(nparr, cv2.IMREAD_COLOR)


def cv2_base64(cv_decode):
    cv_encode = cv2.imencode('.jpg', cv_decode)
    return base64.b64encode(cv_encode[1].tobytes())


def data_uri_to_cv2_img(uri):
    encoded_data = uri.split(',')[1]
    nparr = np.fromstring(encoded_data.decode('base64'), np.uint8)
    img = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    return img


def get_ocr_result(imgBase64):
    proxie = {
        'http': 'http://10.32.140.181:80'
    }

    # print('data:image/jpeg;base64,' + imgBase64)
    data = {'imgBase64': 'data:image/jpg;base64,' + imgBase64}
    resp = requests.post('http://gh-data-hdp-dn-gpu0032.gh.sankuai.com:8843/v1/ocr/common', proxies=proxie,
                         data=json.dumps(data))
    # resp = requests.post('http://localhost:8888/v1/ocr/common', data=json.dumps(data))
    return resp.text

'''
@:parameter URL: image URL, directory: path to save image'''
def downloadImageFromURL(url,directory,name=""):
    # if name is empty, use the url's name
    if(name==""):
        path = directory + url.split("/")[-1]
    else:
        path = directory + name+".jpg"
    try:
        if not os.path.exists(directory):
            os.mkdir(directory)
        if not os.path.exists(path):
            r = requests.get(url)
            r.raise_for_status()
            #使用with语句可以不用自己手动关闭已经打开的文件流
            with open(path,"wb") as f: #开始写文件，wb代表写二进制文件
                f.write(r.content)
            print("web Scrapping complete")
        else:
            print("File already exists")
    except Exception as e:
        print("web Scrapping fail:"+str(e))


if __name__ == "__main__":
    # cv_img = cv2.imread('/Users/yuyanghuang/Desktop/lzlm.jpg')
    # print(type(cv2_base64(cv_img)))
    # print(get_ocr_result(cv2_base64(cv_img).decode()))

    excelPath="/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/Data/门头定位-数据.xlsx"
    saveFolderPath='/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/Data/门头定位-数据图片/'
    dataSet=ReadExcel.getNameURLList(excelPath)
    for dataPiece in dataSet:
        info = (dataPiece['url'])
        downloadImageFromURL(dataPiece['url'],saveFolderPath,dataPiece['name'])
        print(dataPiece['name']," complete")
