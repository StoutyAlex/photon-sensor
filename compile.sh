if [ ! -d './build' ]; then
    mkdir ./build
fi

particle compile photon --quiet --saveTo ./build/firmware.bin
particle flash Photon-1 ./build/firmware.bin --quiet

echo "Finished compile";