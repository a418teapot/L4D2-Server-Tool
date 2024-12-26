import pyperclip as cb
with open("../hostname.txt", "r") as f:  # 打开文件
    hostname = f.read()  # 读取文件
cb.copy("connect "+hostname+":27015")
