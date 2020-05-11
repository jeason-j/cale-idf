# CALE ESP-IDF beta

This is the beginning, and a very raw try, to make CALE compile in the Espressif IOT Development Framework. At the moment to explore how difficult it can be to pass an existing ESP32 Arduino framework project to a ESP-IDF based one and to measure how far we can go compiling this with Espressif's own dev framework. 
It will take some weeks to have a working example. The reason is that we would like to explore alternative libraries like [ESP32 IDF Epaper example](https://github.com/loboris/ESP32_ePaper_example) and to make a version that is compatible with the recently released ESP32-S2

## ESP-IDF learning

This will be created slowly since I know only basic concepts of the IDF framework. So there is probably nothing to run except a few tests. Next steps are: 

1. Port Adafruit GFX to IDF - Fonts
2. Port GxEPD to IDF - Epaper display library
3. Research about Bluetooth in ESP-IDF
4. Refactor and migrate [eink-calendar espressif32-arduino](https://github.com/martinberlin/eink-calendar) Bitmap to GxEPD Buffering functions to this new version
5. Make all the above work together

And after this steps we could finally have a CALE-IDF version that could be compiled on this new framework. The good news is that if it works stable then it will also work on the ESP32-S2 that has only one LX7 Core but is as fast as the ESP32 consuming almost half. 
Please [register in CALE.es](https://cale.es/register) to receive our weekly news and get aware when the ESP-IDF version is ready to be tested.

### Submodules

ESP-IDF uses relative locations as its submodules URLs (.gitmodules). So they link to GitHub. If ESP-IDF is forked to a Git repository which is not on GitHub, you will need to run the script tools/set-submodules-to-github.sh after git clone. The script sets absolute URLs for all submodules, allowing:

    git submodule update --init --recursive
    
to download the submodules (components) for this project.

### Compile this 

If it's an ESP32

    idf.py -D IDF_TARGET=esp32 menuconfig

If you have ESP32S2BETA (The ones that Espressif sent before official release)

    idf.py -D IDF_TARGET=esp32s2beta menuconfig

If it's an ESP32S2

    idf.py -D IDF_TARGET=esp32s2 menuconfig

Make sure to edit "CALE configuration" in the Kconfig menuoptions.

And then just build and flash

    idf.py build
    idf.py flash

To clean and start again in case you change target

    idf.py fullclean

To open the serial monitor

    idf.py monitor

Please note that to exit the monitor in Espressif documentation says Ctrl+] but in Linux this key combination is:

    Ctrl+5