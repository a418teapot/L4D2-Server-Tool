import paramiko

# 设置SSH连接参数
with open("hostname.txt", "r") as f:  # 打开文件
    hostname = f.read()  # 读取文件
port = 22
username = 'steam'
password = 'myszm2024'

# 创建SSH客户端
client = paramiko.SSHClient()

# 自动添加主机密钥
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# 连接远程主机
client.connect(hostname, port, username, password)
client.exec_command('''screen -ls|awk 'NR>=2&&NR<=20{print $1}'|awk '{print "screen -S "$1" -X quit"}'|sh''')   # 执行命令
client.exec_command('./l4d2server/auto_base.sh')   # 执行命令
stdin, stdout, stderr = client.exec_command('screen -ls')   # 执行命令
res, err = stdout.read(), stderr.read()          # stdout.readline()
result = res if res else err
return1=result.decode()
if return1=="No Sockets found in /var/run/screen/S-steam.\n\r\n":
    print("当前没有正在运行的screen实例！")
else:
    print("存在正在运行的实例！")
    print(return1)


# 关闭SSH连接
client.close()
