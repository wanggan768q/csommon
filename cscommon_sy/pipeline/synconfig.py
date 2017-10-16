#!/usr/bin/python
#coding=utf-8

from utils import env
import os
import pexpect
import sys

usr=env.USR_240
pwd=env.PWD_240
ip =env.IP_240
port=env.PORT_240
client_config_path = env.CLIENT_LEVELCONFIG_PATH
server_path = env.PATH_240

def tarconfig():
    print("#tar config")
    cmd = "cd %s; rm -f levelconfig.tar.gz" % client_config_path
    os.system(cmd)
    cmd = "cd %s;tar zcvf levelconfig.tar.gz *" % client_config_path
    os.system(cmd)
    print("#tar success")

def removeconfig():
    cmd = "cd %s; rm -f levelconfig.tar.gz" % client_config_path
    os.system(cmd)

def upload(usr,pwd,ip,port):
    print("#upload begin")
    cmd = "/usr/bin/sftp -oPort=%d %s@%s" %(port,usr,ip)
    p = pexpect.spawn(cmd)
    i = p.expect([".*\(yes/no\)",".*assword:"])
    if i == 0:
        p.sendline('yes')
        p.expect('.*assword:')
    p.sendline(pwd)
    p.expect("sftp>")
    p.sendline('lcd %s' % client_config_path)
    p.expect("sftp>")
    p.sendline("cd %s/tmp/" % server_path)
    p.expect("sftp>")
    p.sendline("put levelconfig.tar.gz")
    p.expect("sftp>",60)
    p.sendline("quit")
    print("#upload sucess")

def restart(usr,pwd,ip,port):
    cmd = "ssh -p %d %s@%s" %(port,usr,ip)
    p = pexpect.spawn(cmd)
    i = p.expect([".*\(yes/no\)",".*assword:"])
    if i == 0:
        p.sendline('yes')
        p.expect('.*assword:')
    p.sendline(pwd)
    p.expect("\[root@240 ~\]#")

    #预处理
    p.sendline("cd %s/tmp" % server_path)
    p.expect("\[root@240 tmp\]#")
    p.sendline("./check.sh")
    p.expect("\[root@240 tmp\]#")
	
    #commit to svn
    print("##svn commit begin")
    p.sendline("cd %s/table/" % server_path)
    p.expect("\[root@240 table\]#")
    p.sendline("tar zxvf ../tmp/levelconfig.tar.gz")
    p.expect("\[root@240 table\]#")
    p.sendline('svn ci -m "commit by script" *')
    p.expect("\[root@240 table\]#")
    print("##svn commit sucess")
    
    print("##restart begin")
    p.sendline("cd %s" % server_path)
    p.expect("\[root@240 bin\]#")
    p.sendline("./k;./r")
    p.expect("\[root@240 bin\]#")
    p.sendline("./lev_ali.sh")
    p.expect("\[root@240 bin\]#")
    p.sendline("rm -f tmp/levelconfig.tar.gz")
    p.expect("\[root@240 bin\]#")
    p.sendline("exit")
    print("##restart success")

def start():
    tarconfig()
    upload(usr,pwd,ip,port)
    restart(usr,pwd,ip,port)
    removeconfig()