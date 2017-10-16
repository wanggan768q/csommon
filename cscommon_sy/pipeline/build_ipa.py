#!/usr/bin/env python
#coding=utf-8

import os
import paramiko
import scpclient
import sys
from utils import env
import pexpect

def buildPackage(region, platform, build):
    if env.isMacSystem():
        checkbundlePath = env.GAMEPROJ_PATH + "/AssetBundles"
        checkpackagePath = env.GAMEPROJ_PATH + "/Build"
        exitBundle = os.path.exists(checkbundlePath)
        exitPackage = os.path.exists(checkpackagePath)
        if exitBundle == 1:
                          print "exitBundleYES"
                          func = 'rm ' + '-rf ' + checkbundlePath
                          os.system(func)
                          print 'delete AssetBundles successed'
    
        if exitPackage == 1:
                          print "exitPackageYES"
                          func = 'rm ' + '-rf ' + checkpackagePath
                          os.system(func)
                          print 'delete packagePath successed'

        print 'Begin Build'
        #os.system(env.UNITY_PATH + " -projectPath " + env.GAMEPROJ_PATH +
        #    " -executeMethod " + buildAssetBundleMethod(region, platform, build) + " -quit")
        os.system(env.UNITY_PATH + " -projectPath " + env.GAMEPROJ_PATH + 
            " -executeMethod " + buildPackageMethod(region, platform, build) + " -quit")
        os.chdir(xcodePath(region, platform, build))
        os.system("xcodebuild clean")
        os.system("xcodebuild")
        os.system("xcrun -sdk iphoneos PackageApplication -v " + 
            bundlePath(region, platform, build) + " -o " + 
            packagePath(region, platform, build))

              
                           
def uploadAssetBundle(region, platform, build):
    print("upload the asset bundle...")
    client = paramiko.SSHClient()
    client.load_system_host_keys()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(env.UPLOAD_ASSETBUNDLE_URL, 
        username=env.UPLOAD_ASSETBUNDLE_USER, 
        password=env.UPLOAD_ASSETBUNDLE_PASSWD)

    remotePath = assetBundleRemotePath(region, platform, build)
    with scpclient.closing(scpclient.WriteDir(client.get_transport(), remotePath)) as scp:
        if "dev" == build:
            scp.send_dir(assetBundlePath(region, platform, build), progress=showProgress)
        elif "beta" == build:
            scp.send_dir(assetBundlePath(region, platform, build), progress=showProgress)
        elif "release" == build:
            scp.send_dir(assetBundlePath(region, platform, build), progress=showProgress)

def uploadPackage(region, platform, build):
    print("upload the ipa...")
    client = paramiko.SSHClient()
    client.load_system_host_keys()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(env.UPLOAD_PACKAGE_URL, 
        username=env.UPLOAD_PACKAGE_USER, 
        password=env.UPLOAD_PACKAGE_PASSWD)
    if "dev" == build:
        cmd = 'sftp -oPort=22 '+ env.UPLOAD_PACKAGE_USER + "@" +env.UPLOAD_PACKAGE_URL
        p = pexpect.spawn(cmd)
        p.logfile = sys.stdout
        p.expect('.*assword:')
        p.sendline(env.UPLOAD_PACKAGE_PASSWD)
        p.expect('sftp>')
        p.sendline('cd ' + env.UPLOAD_PACKAGE_DIR)
        p.expect('sftp>')
        p.sendline('put ' + packagePath(region, platform, build) + " " + "baimao-for-dev.ipa")
        p.expect('sftp>')
        p.sendline('exit')
    elif "beta" == build:
        cmd = 'sftp -oPort=22 '+ env.UPLOAD_PACKAGE_USER + "@" +env.UPLOAD_PACKAGE_URL
        p = pexpect.spawn(cmd)
        p.logfile = sys.stdout
        p.expect('.*assword:')
        p.sendline(env.UPLOAD_PACKAGE_PASSWD)
        p.expect('sftp>')
        p.sendline('cd ' + env.UPLOAD_PACKAGE_DIR)
        p.expect('sftp>')
        p.sendline('put ' + packagePath(region, platform, build) + " " + "baimao-for-test.ipa")
        p.expect('sftp>')
        p.sendline('exit')
    elif "release" == build:
        cmd = 'sftp -oPort=22 '+ env.UPLOAD_PACKAGE_USER + "@" +env.UPLOAD_PACKAGE_URL
        p = pexpect.spawn(cmd)
        p.logfile = sys.stdout
        p.expect('.*assword:')
        p.sendline(env.UPLOAD_PACKAGE_PASSWD)
        p.expect('sftp>')
        p.sendline('cd ' + env.UPLOAD_PACKAGE_DIR)
        p.expect('sftp>')
        p.sendline('put ' + packagePath(region, platform, build) + " " + "baimao-for-release.ipa")
        p.expect('sftp>')
        p.sendline('exit')

def showProgress(remote_filename, size, file_pos):
    print("upload file: [{0}] {1}k/{2}k".format(
        remote_filename, file_pos/1024, size/1024))

def buildAssetBundleMethod(region, platform, build):
    return "BlingARPG.BuildMenu.BuildAssetBundles_" + region + "_iOS_" + platform + "_" + build

def buildPackageMethod(region, platform, build):
    return "BlingARPG.BuildMenu.BuildPlayer_" + region + "_iOS_" + platform + "_" + build

def assetBundlePath(region, platform, build):
    return env.GAMEPROJ_PATH + "/AssetBundles/" + region + "/iOS/" + platform + "/" + build

def assetBundleRemotePath(region, platform, build):
    return env.UPLOAD_ASSETBUNDLE_DIR + region + "/iOS/" + platform + "/"

def xcodePath(region, platform, build):
    return env.GAMEPROJ_PATH + "/Build/" + region + "/iOS/" + platform + "/" + build

def bundlePath(region, platform, build):
    return env.GAMEPROJ_PATH + "/Build/" + region + "/iOS/" + platform + "/" + build + "/build/Release-iphoneos/arpg.app"

def symbolPath(region, platform, build):
    return env.GAMEPROJ_PATH + "/Build/" + region + "/iOS/" + platform + "/" + build + "/build/Release-iphoneos/arpg.app.dSYM"

def packagePath(region, platform, build):
    return env.GAMEPROJ_PATH + "/Build/" + region + "/iOS/" + platform + "/" + build + "/build/Release-iphoneos/arpg.ipa"

def packageRemotePath(region,platform,build):
    return env.UPLOAD_PACKAGE_DIR
