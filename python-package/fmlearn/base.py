# -*- coding:utf-8 -*-
# @Time : 2020/1/12 20:43
# @Author : naihai
import ctypes


def load_lib():
    return ctypes.cdll.LoadLibrary("E:\CLion\Projects\FMLearn\cmake-build-debug\libFMLearn.dll")


_LIB = load_lib()
