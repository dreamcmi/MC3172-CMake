# SPDX-FileCopyrightText: 2022 Darren <1912544842@qq.com>
# SPDX-License-Identifier: Apache-2.0

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
cmake_minimum_required(VERSION 3.20)

# 工具链设置
set(TOOLPATH  D:/0wch/toolchain/RISCVEmbeddedGCC/bin/riscv-none-embed-)
set(CMAKE_C_COMPILER ${TOOLPATH}gcc.exe)
set(CMAKE_CXX_COMPILER ${TOOLPATH}g++.exe)
set(CMAKE_ASM_COMPILER ${TOOLPATH}gcc.exe)
set(CMAKE_AR ${TOOLPATH}ar.exe)
set(CMAKE_OBJCOPY ${TOOLPATH}objcopy.exe)
set(CMAKE_OBJDUMP ${TOOLPATH}objdump.exe)
set(SIZE ${TOOLPATH}size.exe)
set(NM ${TOOLPATH}nm.exe)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


# 项目设置
project(mc3172-cmake C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

# 编译参数 一般不用改
add_compile_options(-march=rv32imc -mabi=ilp32 -std=gnu99)
add_compile_options(-mtune=size -msmall-data-limit=8 -mstrict-align -mno-save-restore -mno-div -mbranch-cost=1)
add_compile_options(-fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin)

# 编译等级
add_compile_options(-O3)

# 宏定义
# add_definitions()


# 头文件路径
include_directories(
    MC3172
    USER_CODE
)


# 源码文件
file(GLOB_RECURSE SOURCES 
                "MC3172/thread_start.c"
                "USER_CODE/*.c")

# 链接参数
set(LINKER_SCRIPT  ${CMAKE_SOURCE_DIR}/MC3172/MC3172.lds)
add_link_options(-nostartfiles 
                -nodefaultlibs 
                -nostdlib
                -Xlinker --gc-sections  
                -Wl,--print-memory-usage
                -Wl,-Map,${PROJECT_NAME}.map 
                --specs=nano.specs 
                --specs=nosys.specs)
add_link_options(-T ${LINKER_SCRIPT})

# 编译可执行文件
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})


# 输出hex和bin
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(LST_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.lst)
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJDUMP} --all-headers --demangle --disassemble $<TARGET_FILE:${PROJECT_NAME}.elf> > ${LST_FILE}
)