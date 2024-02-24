#include <jni.h>
#include <string>

#define RUAPU_IMPLEMENTATION
#include "ruapu.h"


char buf[40];
std::string info = "";
#define PRINT_ISA_SUPPORT(isa) \
                              sprintf(buf, "%s = %d\n", #isa, ruapu_supports(#isa)); \
                              info += std::string(buf);



extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ruandroid_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    ruapu_init();

#if __ANDROID__
    PRINT_ISA_SUPPORT(neon)
    PRINT_ISA_SUPPORT(vfpv4)
    PRINT_ISA_SUPPORT(cpuid)
    PRINT_ISA_SUPPORT(asimdhp)
    PRINT_ISA_SUPPORT(asimddp)
    PRINT_ISA_SUPPORT(asimdfhm)
    PRINT_ISA_SUPPORT(bf16)
    PRINT_ISA_SUPPORT(i8mm)
    PRINT_ISA_SUPPORT(sve)
    PRINT_ISA_SUPPORT(sve2)
    PRINT_ISA_SUPPORT(svebf16)
    PRINT_ISA_SUPPORT(svei8mm)
    PRINT_ISA_SUPPORT(svef32mm)
    PRINT_ISA_SUPPORT(sha3)
    PRINT_ISA_SUPPORT(sha512)
    PRINT_ISA_SUPPORT(sm3)
    PRINT_ISA_SUPPORT(sm4)
    PRINT_ISA_SUPPORT(amx)

#endif

    std::string hello = "Hello from ruapu\n" + info;
    return env->NewStringUTF(hello.c_str());
}