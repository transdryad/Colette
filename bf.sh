#!/bin/bash
qmk setup -y
cp -r firmware/* ~/qmk_firmware/keyboards/colette
qmk compile -kb colette -km default
qmk flash -kb colette -km default
mkdir firmware-out
cp ~/qmk_userspace/colette_default.uf2 firmware-out/colette_default.uf2
echo "Cleaning Up..."
rm -rf ~/qmk_firmware