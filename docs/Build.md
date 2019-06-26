# Build

Install **VitaSDK** with [VDPM](https://github.com/vitasdk/vdpm). You can follow the instruction by the [VitaSDK team](https://vitasdk.org/).

When your computer is ready to compile some code, just run the followed command. Easy :smiley:

```shell
cmake .
make
```

The CMake configuration will download and update all dependencies used by VitaMaterialKit.

You can also use the followed commands to develop quickly your application thanks to Vita3K or send your files through the USB or the FTP. 

```shell
#send eboot.bin file with FTP
make send
#send vpk with FTP
make send_vpk
#copy eboot.bin file with USB
make copy
#send vpk with USB
make copy_vpk
#emulate Update eboot.bin and launch app in Vita3K
make emulate
#emulate_vpk Install the app in Vita3K
make emulate
```