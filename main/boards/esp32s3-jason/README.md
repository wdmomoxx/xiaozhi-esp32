# 脚本编译打包固件

```
python scripts/release.py esp32s3-jason
```

# IDF编译配置命令

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
Xiaozhi Assistant -> Board Type -> ESP32S3 JASON
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
