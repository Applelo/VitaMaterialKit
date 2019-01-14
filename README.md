# VitaMaterialProject

### Kit in C++ inspired by Material UI to create quickly a beautiful application for PSVita systems

Wiki will be available soon to explain how to create an app and details each functions in each class.

## Showcase

* Vita-CTP-Shortcut
#* HueVita
#* VitaKodiRemote

## Changelog

### Version 0.5 - First Version

- Initial Release


## Build
Install **VitaSDK** with [**VDPM**](https://github.com/vitasdk/vdpm) and run the followed commands :

```shell
cmake .
make
```

You can also use this followed commands to send directly built files :

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

## Credits

* Developed & maintained by *Applelo*
* *coderx3* (aka devingDev) for IME, Pad and Touch functions used in VitaCord
* *Tuxbot123* for his suggestions and his support
* My master, *MisterAlex*


* *Google* for Material Guidelines, Fonts, Components, Themes
* [Material Design Icons](https://github.com/Templarian/MaterialDesign-Webfont/) teams for all icons
* *juliettef* for [Material Design Icons Headers](https://github.com/juliettef/IconFontCppHeaders)

