#!/usr/bin/env python
#coding=utf-8

import sys
import argparse
from pipeline import export_config
from pipeline import build_ipa

# 解析命令行
parser = argparse.ArgumentParser(description='Deploy this project.')
parser.add_argument('--dev_build', 
    help='Build version: develop')
parser.add_argument('--dev_upload_assetbundle', 
    help='Upload asset bundle for: develop')
parser.add_argument('--dev_upload_package', 
    help='Upload package for: develop')

parser.add_argument('--beta_build', 
    help='Build version: beta')
parser.add_argument('--beta_upload_assetbundle', 
    help='Upload asset bundle for: develop')
parser.add_argument('--beta_upload_package', 
    help='Upload package for: develop')

parser.add_argument('--release_build', 
    help='Build version: release')
parser.add_argument('--release_upload_assetbundle', 
    help='Upload asset bundle for: develop')
parser.add_argument('--release_upload_package', 
    help='Upload package for: develop')
args = parser.parse_args()

# 构建过程
def processRoutine():
    # 导出配置文件
    # export_config.exportConfig()

    # 构建客户端
    if args.dev_build:
        build_ipa.buildPackage("cn", "AppStore", "dev")
    if args.dev_upload_assetbundle:
        build_ipa.uploadAssetBundle("cn", "AppStore", "dev")
    if args.dev_upload_package:
        build_ipa.uploadPackage("cn", "AppStore", "dev")

    if args.beta_build:
        build_ipa.buildPackage("cn", "AppStore", "beta")
    if args.beta_upload_assetbundle:
        build_ipa.uploadAssetBundle("cn", "AppStore", "beta")
    if args.beta_upload_package:
        build_ipa.uploadPackage("cn", "AppStore", "beta")

    if args.release_build:
        build_ipa.buildPackage("cn", "AppStore", "release")
    if args.release_upload_assetbundle:
        build_ipa.uploadAssetBundle("cn", "AppStore", "release")
    if args.release_upload_package:
        build_ipa.uploadPackage("cn", "AppStore", "release")

if len(sys.argv) <= 1:
    # 如果没有命令行参数，进入菜单模式
    def toggleDev():
        hasEnabled = args.dev_build or \
                     args.dev_upload_assetbundle or \
                     args.dev_upload_package
        args.dev_build = not hasEnabled
        args.dev_upload_assetbundle = not hasEnabled
        args.dev_upload_package = not hasEnabled
    def toggleBeta():
        hasEnabled = args.beta_build or \
                     args.beta_upload_assetbundle or \
                     args.beta_upload_package
        args.beta_build = not hasEnabled
        args.beta_upload_assetbundle = not hasEnabled
        args.beta_upload_package = not hasEnabled
    def toggleRelease():
        hasEnabled = args.release_build or \
                     args.release_upload_assetbundle or \
                     args.release_upload_package
        args.release_build = not hasEnabled
        args.release_upload_assetbundle = not hasEnabled
        args.release_upload_package = not hasEnabled

    def toggleDevBuild():
        args.dev_build = not args.dev_build
    def toggleDevUploadAssetBundle():
        args.dev_upload_assetbundle = not args.dev_upload_assetbundle
    def toggleDevUploadPackage():
        args.dev_upload_package = not args.dev_upload_package

    def toggleBetaBuild():
        args.beta_build = not args.beta_build
    def toggleBetaUploadAssetBundle():
        args.beta_upload_assetbundle = not args.beta_upload_assetbundle
    def toggleBetaUploadPackage():
        args.beta_upload_package = not args.beta_upload_package

    def toggleReleaseBuild():
        args.release_build = not args.release_build
    def toggleReleaseUploadAssetBundle():
        args.release_upload_assetbundle = not args.release_upload_assetbundle
    def toggleReleaseUploadPackage():
        args.release_upload_package = not args.release_upload_package

    def process():
        processRoutine()
        sys.exit(0)
    def exitMenu():
        sys.exit(0)
    def markTitle(enbale):
        if enbale:
            return "[-]"
        else:
            return "[ ]"

    def refreshMenu(menu):
        menu.clearOptions()
        menu.addOptions([
            {"name": "toggle-dev", "function":toggleDev},
            {"name": "toggle-beta", "function":toggleBeta},
            {"name": "toggle-release", "function":toggleRelease},

            {"name": markTitle(args.dev_build) + 
                "dev-build", "function":toggleDevBuild},
            {"name": markTitle(args.dev_upload_assetbundle) + 
                "dev-upload-assetbundle", "function":toggleDevUploadAssetBundle},
            {"name": markTitle(args.dev_upload_package) + 
                "dev-upload-package", "function":toggleDevUploadPackage},

            {"name": markTitle(args.beta_build) + 
                "beta-build", "function":toggleBetaBuild},
            {"name": markTitle(args.beta_upload_assetbundle) + 
                "beta-upload-assetbundle", "function":toggleBetaBuild},
            {"name": markTitle(args.beta_upload_package) + 
                "beta-upload-package", "function":toggleBetaBuild},

            {"name": markTitle(args.release_build) + 
                "release-build", "function":toggleReleaseBuild},
            {"name": markTitle(args.release_upload_assetbundle) + 
                "release-upload-assetbundle", "function":toggleReleaseBuild},
            {"name": markTitle(args.release_upload_package) + 
                "release-upload-package", "function":toggleReleaseBuild},

            {"name": "process", "function":process},
            {"name": "exit", "function":exitMenu}])

    from menu import menu
    mainMenu = menu.Menu("Choose and build:", update=refreshMenu)
    refreshMenu(mainMenu)
    mainMenu.open()
else:
    # 如果有命令行参数, 直接运行构建.
    processRoutine()
