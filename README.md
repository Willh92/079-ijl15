# CMS079-ijl15

移植与https://github.com/BeiDouMS/BeiDou-ijl15

主要是为了移植https://github.com/Chronicle20/gms-83-dll这个框架

代码未清理，除了启用的功能能外，其他基址还是083的


## 使用方法
已测试的开发工具 VS 2022，SDK 10，工具集 VS2022（v144）

使用vs打开的时候注意，要使用 Release x86 的模式生成解决方案

生成后可在 out/Release 目录下找到 ijl15.dll

支持两种模式

直接加载模式：
直接覆盖客户端的ijl15.dll,并修改配置文件中ijl15hook为false

HOOK模式:
先把客户端原本的ijl15.dll重命名成2ijl15.dll，然后把生成的ijl15.dll拷贝到客户端目录下，ijl15hook为true

两种模式均需要把项目根目录下的config.ini同样复制到客户端目录下，具体配置都在config.ini中

具体功能查看配置文件

## 主要额外添加的特殊功能

- 双击跳跃键使用二段跳
- 屏蔽了聊天室按钮弹窗仅发数据包（可用作）

# 仅供学习交流使用!!!