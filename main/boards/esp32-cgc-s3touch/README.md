
# 编译打包固件

```
python scripts/release.py esp32-cgc-s3touch
```
# IDF编译配置及修改
复制开发板文件夹下的sdkconfig文件到项目根目录，修改main/display/lcd_display.cc中SpiLcdDisplay函数下的.swap_bytes = 0,，不修改的话屏幕颜色不正常

# 编译下载固件

```bash
idf.py build flash monitor
```

# 打包固件

```bash
esptool.py --chip esp32s3 merge_bin -o esp32-cgc-s3touch.bin --flash_mode dio --flash_size 16MB --flash_freq 80m 0x0 build\bootloader\bootloader.bin 0x8000 build\partition_table\partition-table.bin 0xd000 build\ota_data_initial.bin 0x10000 build\srmodels\srmodels.bin 0x100000 build\xiaozhi.bin
```
