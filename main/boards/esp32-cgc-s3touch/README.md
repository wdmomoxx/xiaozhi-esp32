
# 编译打包固件

```
python scripts/release.py esp32-cgc-s3touch
```
# IDF编译配置及修改
复制开发板文件夹下的sdkconfig文件到项目根目录，修改main/display/lcd_display.cc中SpiLcdDisplay函数下的.swap_bytes = 0,，不修改的话屏幕颜色不正常

