import os
import paramiko
import time

try:
    # 创建一个名为"maps"的文件夹
    path = "maps"
    os.mkdir(path)
    print("Folder not exists!")
    input()
    exit()
except:
    print("Folder already exists!")

def getfiles():
    filenames=os.listdir(r'.\\maps')
    return filenames

def upload_file_with_progress(hostname, username, password, remote_path, local_path):
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(hostname=hostname, username=username, password=password)
    sftp = ssh.open_sftp()
    # get local file size
    local_file_size = os.stat(local_path).st_size
    print ("local_file_size:{}".format(local_file_size))
    # print progress
    with open(local_path, 'rb') as f:
        def callback(transferred, local_file_size):
            percent = float(transferred) * 100 / local_file_size
            print("Upload %.2f%% of the file." % percent,end='\r')
        # transfer 32768 bytes as SSH slice, put local file to remote
        sftp.putfo(f, remote_path, local_file_size, callback=callback)
    sftp.close()
    ssh.close()
 
if __name__ == "__main__":
    # hostname = "*****"
    # 设置SSH连接参数
    with open("hostname.txt", "r") as f:  # 打开文件
    hostname = f.read()  # 读取文件
    port = 22
    # username = "********"
    username = "steam"
    # password = "*****"
    password = "myszm2024"
    remote_path_upload = "/home/steam/l4d2server/left4dead2/addons/"
    local_path_upload = ".\\maps\\"
    file_list=getfiles()

    for file_name in file_list:
        
        cutline = "===========================================================================\n"
        print (cutline)
        print("Uploading "+file_name)
        # upload file and calculate cost
        print ("Upload Start, 32678 bytes as default SSH slice: ")
        upload_start = time.time()
        upload_file_with_progress(hostname, username, password, remote_path_upload+file_name, local_path_upload+file_name)
        upload_end = time.time()
        upload_cost = upload_end - upload_start
        print ("Upload successfully! Cost {}s\n".format(upload_cost))
        
    # 创建SSH客户端
    client = paramiko.SSHClient()

    # 自动添加主机密钥
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    # 连接远程主机
    client.connect(hostname, port, username, password)

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
