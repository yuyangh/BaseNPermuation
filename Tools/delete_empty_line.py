# -*- coding: utf-8 -*-
import sys


def clearBlankLine(documentHasEmptyLine, newDocumentWithoutEmptyLine):
    file1 = open(documentHasEmptyLine, 'r', encoding='utf-8')  # 要去掉空行的文件
    file2 = open(newDocumentWithoutEmptyLine, 'w', encoding='utf-8')  # 生成没有空行的文件
    try:
        for line in file1.readlines():
            if line == '\n':
                line = line.strip("\n")
            file2.write(line)
    finally:
        file1.close()
        file2.close()


if __name__ == '__main__':
    documentHasEmptyLine = '/Users/yuyanghuang/PycharmProjects/MachineLearning/OCR_Project/data/differentEstimatedPicturePath.txt'
    newDocumentWithoutEmptyLine = 'differentEstimatedPicturePath.txt'
    clearBlankLine(documentHasEmptyLine, newDocumentWithoutEmptyLine)
