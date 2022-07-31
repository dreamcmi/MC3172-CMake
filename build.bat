::SPDX-FileCopyrightText: 2022 Darren <1912544842@qq.com>
::SPDX-License-Identifier: Apache-2.0

@echo off

if exist build (
echo Found build/ 
cd build
cmake -GNinja ..
ninja
) else (
echo Not Found build/
mkdir build
cd build
cmake -GNinja ..
ninja
)