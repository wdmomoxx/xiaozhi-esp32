# 相关资料：
- [ESP32-CGC-S3模块开发版小智AI](https://www.wdmomo.fun:81/doc/index.html?file=001_%E8%AE%BE%E8%AE%A1%E9%A1%B9%E7%9B%AE/0001_%E5%B0%8F%E6%99%BAAI/007_ESP32-CGC-S3%E6%A8%A1%E5%9D%97%E5%BC%80%E5%8F%91%E7%89%88%E5%B0%8F%E6%99%BAAI)

# 编译配置命令

**配置编译目标为 ESP32S3：**

```bash
idf.py set-target esp32s3
```

**打开 menuconfig：**

```bash
idf.py menuconfig
```

**选择板子：**

```
Xiaozhi Assistant -> Board Type -> ESP32 CGC S3模块
```

**选择USB接口作为控制台输出：**

```
Component config -> ESP System Settings -> Channel for console output -> USB Serial/JTAG Controller
Component config -> ESP System Settings -> Channel for console secondary output -> No secondary console
```

**编译：**

```bash
idf.py build
```
