rm -rf "build" && mkdir "build"
cd "build" || exit 1
cmake ..
make && make install
cd ..
