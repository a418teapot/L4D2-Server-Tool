import shutil
import os, sys

# 打开文件
path = "..\\maps"
dirs = os.listdir( path )
for file in dirs:
    shutil.copy('..\\maps\\'+file, r"D:\\SteamLibrary\\steamapps\\common\\Left 4 Dead 2\\left4dead2\\addons")
    print(file+"已经复制")
print("文件已经复制完毕")
