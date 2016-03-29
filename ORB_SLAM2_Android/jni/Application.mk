APP_STL := gnustl_static
APP_CPPFLAGS := -frtti -fexceptions -mfloat-abi=softfp -mfpu=neon -std=gnu++0x -Wno-deprecated \
-ftree-vectorize -ffast-math -fsingle-precision-constant
NDK_TOOLCHAIN_VERSION := 4.8
APP_ABI :=armeabi armeabi-v7a
APP_OPTIM := release
APP_SHORT_COMMANDS      := true

