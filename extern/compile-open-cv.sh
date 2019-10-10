CURRENT_DIR=`pwd`
PARENT_DIR="$(dirname "$CURRENT_DIR")"
INSTALL_DIR=${1:-$PARENT_DIR/build/opencv}
printf "Command: $0\n"
printf "Current Directory: $CURRENT_DIR \n"
printf "Install Directory: $INSTALL_DIR \n"
OPENCV_COMPILE_OPTIONS=""
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_opencv_ittnotify=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_ITT=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DCV_DISABLE_OPTIMIZATION=ON"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_CUDA=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_OPENCL=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_OPENCLAMDFFT=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_OPENCLAMDBLAS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_VA_INTEL=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DCPU_BASELINE_DISABLE=ON"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_TESTING=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_PERF_TESTS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_TESTS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DCMAKE_BUILD_TYPE=RELEASE"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_EXAMPLES=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_DOCS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_opencv_apps=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_SHARED_LIBS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DOpenCV_STATIC=ON"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_1394=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_ARITH_DEC=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_ARITH_ENC=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_CUBLAS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_CUFFT=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_FFMPEG=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_GDAL=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_GSTREAMER=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_GTK=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_HALIDE=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_JASPER=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_NVCUVID=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_OPENEXR=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_PROTOBUF=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_PTHREADS_PF=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_QUIRC=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_V4L=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DWITH_WEBP=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_LIST=\"core,imgcodecs,imgproc\""
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DANDROID_NDK=$ANDROID_HOME/ndk-bundle"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DCMAKE_TOOLCHAIN_FILE=$ANDROID_HOME/ndk-bundle/build/cmake/android.toolchain.cmake"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DANDROID_NATIVE_API_LEVEL=android-21"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_JAVA=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_ANDROID_EXAMPLES=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_ANDROID_PROJECTS=OFF"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DANDROID_STL=c++_shared"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DBUILD_SHARED_LIBS=ON"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DCMAKE_INSTALL_PREFIX:PATH=$INSTALL_DIR"
OPENCV_COMPILE_OPTIONS="$OPENCV_COMPILE_OPTIONS -DOPENCV_INCLUDE_INSTALL_PATH=$INSTALL_DIR/include"
mkdir -p builds
cd builds
mkdir -p opencv
cd opencv
mkdir -p arm64-v8a
cd arm64-v8a
cmake ../../../opencv $OPENCV_COMPILE_OPTIONS -DANDROID_ABI=arm64-v8a
make
make install
cd ..
mkdir -p armeabi-v7a
cd armeabi-v7a
cmake ../../../opencv $OPENCV_COMPILE_OPTIONS -DANDROID_ABI=armeabi-v7a
make
make install
cd ..
mkdir -p x86
cd x86
cmake ../../../opencv $OPENCV_COMPILE_OPTIONS -DANDROID_ABI=x86
make
make install
cd ..
mkdir -p x86_64
cd x86_64
cmake ../../../opencv $OPENCV_COMPILE_OPTIONS -DANDROID_ABI=x86_64
make
make install
cd ..