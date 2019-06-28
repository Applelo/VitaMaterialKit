# IME

The IME function allows you to display the PSVita keyboard. You can access to every type of keyboards and options available.

## Functions

### Constructor UtilsIME()

Create the object and init system for IME

**Return**
* Nothing

```cpp
UtilsIME *ime = new UtilsIME();
```

### Getter

#### getUserText()

Launch the IME keyboard and return the text input

**Args**
* (const char *) title: The title of the keyboard
* (const char *) showText: The text already input in the keyboard. By default, the value is empty
* (unsigned int/SceImeType) type:  The keyboard type. By default, the value is SCE_IME_TYPE_BASIC_LATIN
* (int) maxTextLength: The max text length. By default, the value is 128
* (unsigned int/SceImeOption) option: Additional option. By default, there are no option

**Return**
* (std::string) The string of the text input

```cpp
textarea = ime->getUserText("Text", textarea.c_str(), SCE_IME_TYPE_BASIC_LATIN, 200, SCE_IME_OPTION_MULTILINE);
```


#### getStatus()

Get the current status of the IME object

**Return**
* (int/SceCommonDialogStatus) The status of the IME object