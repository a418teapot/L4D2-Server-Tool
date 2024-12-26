import os

try:
    # 创建一个名为"start"的文件夹
    path = "../start"
    os.mkdir(path)
    print("start is created successfully")
except:
    print("start already exists!")

try:
    # 创建一个名为"maps"的文件夹
    path = "../maps"
    os.mkdir(path)
    print("maps is created successfully")
except:
    print("maps already exists!")


