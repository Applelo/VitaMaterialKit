#include "Ui.hh"

void Ui::init() {
    // For example
    // https://material.io/tools/color/#!/?view.left=0&view.right=0&primary.color=212121&secondary.color=90A4AE&secondary.text.color=FAFAFA&primary.text.color=FAFAFA
    colorSchemeHEX primaryThemeColor;
    colorSchemeHEX secondaryThemeColor;

    primaryThemeColor.normal = "#212121";
    primaryThemeColor.dark = "#000000";
    primaryThemeColor.light = "#484848";
    primaryThemeColor.text = "#fafafa";

    secondaryThemeColor.normal = "#90a4ae";
    secondaryThemeColor.dark = "#62757f";
    secondaryThemeColor.light = "#c1d5e0";
    secondaryThemeColor.text = "#fafafa";

    this->loadFonts();

    this->theme = new UiTheme(primaryThemeColor, secondaryThemeColor);
    //this->texts = new UiTexts(roboto);
    icons = UiIcons(mdi);
   // this->buttons = new UiButtons(theme, texts, icons);
}


Ui::Ui() {
    this->init();
}

void Ui::loadFonts() {

    //Roboto
    /*std::string family = "Roboto";
    SceIoDirent gDir;
    std::string fontsPath = DEFAULT_FONTS_PATH;
    fontsPath = fontsPath + family;

    int fd = sceIoDopen(fontsPath.c_str());//open fonts folder

    std::string fontPath, fileName, fontName;

    fontsPath.append("/");//add slash for folder

    while (sceIoDread(fd, &gDir) > 0) {
        fileName = gDir.d_name;
        fontPath = fontsPath + fileName;//get the path of the file

        fontName = fileName.erase(0, family.length() + 1);//remove the family name and -
        fontName = fontName.erase(fontName.length() - 4, fontName.length());//remove .ttf
        roboto[fontName] = vita2d_load_font_file(fontPath.c_str());

    }

    sceIoClose(fd);*/

    //mdi
    mdi = vita2d_load_font_file(DEFAULT_MATERIAL_ICON_PATH);

}
