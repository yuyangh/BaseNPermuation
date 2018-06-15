# -*- coding: utf-8 -*-
import os
import shutil

'''
copy files (list as file path) in selectedFilesListPath from originalDirectory to originalDirectory
'''
originalDirectory = "/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/Data/门头定位-数据图片/"
newDirectory = "/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/Data/门头定位-数据图片 estimate对比不一致 原图/"
selectedFilesListPath = '/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/Data/differentEstimatedPicturePath.txt'

if __name__ == "__main__":
    filesList = os.listdir(originalDirectory)
    copyFilesListFile = open(selectedFilesListPath, mode="r", encoding='utf-8')
    copyFilesList = copyFilesListFile.readlines()

    for index in range(len(copyFilesList)):
        copyFilesList[index] = copyFilesList[index].strip()
        copyFilesList[index] = copyFilesList[index].split("/")[-1][:len(copyFilesList[index].split("/")[-1]) - len(
            copyFilesList[index].split("/")[-1].split(".")[-1]) - 1]

    for file in filesList:
        slices = file.split(".")
        fileName = ""
        for index in range(len(slices) - 1):
            fileName += (slices[index])
            fileName += (".")
        fileName = fileName[:len(fileName) - 1]
        fileExtentionName = slices[len(slices) - 1]
        aa = fileName
        bb = fileExtentionName
        # print(fileName)
        for copyFile in copyFilesList:
            if copyFile in fileName:
                oldPath = originalDirectory + fileName + "." + fileExtentionName
                newPath = newDirectory + fileName + "." + fileExtentionName
                shutil.copyfile(oldPath, newPath)
    copyFilesListFile.close()
