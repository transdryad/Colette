# Colette

![Colette](colette-rev3.png)

A keyboard designed to be ergonomic, clean, convenient, maintainable, and versatile.
It is optimized for English, but can type every character supported by the US International layout (though it's not followed or fully required for basic usage.)
By default, it uses Colemak Mod-DH with a few changes to punctuation.

* Keyboard Maintainer: [Hazel Viswanath](https://github.com/transdryad)
* Hardware Supported: Colette PCB, RPi/Orpheus Pico v1, Cherry MX keys, standard TRS jack

# Software used:
Kicad, Pycharm, FreeCAD, QMK, and Keyboard-Layout-Editor.com

# Firmware:
To compile & flash formware, install qmk system-wide and run bf.sh.
When it's "waiting for drive," plug in while pressing the BOOTSEL button on the PICO.
WARNING: the script will delete qmk firmware monorepo tree.
Backup any changes.