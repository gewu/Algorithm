#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Singleton(type):

    def __init__(cls, name, bases, dict_):
        super(Singleton, cls).__init__(name, bases, dict_)
        cls.instance = None
    
    def __call__(cls, *args, **kw):
        if cls.instance is None:
            cls.instance = super(Singleton,cls).__call__(*args, **kw)
        return cls.instance

class test(object):
    __metaclass__ = Singleton

    def __init__(self):
        self.a = 1
        self.b = 2

if __name__ == "__main__":
    t1 = test()
    t2 = test()

    t1.a = 5
    print t2.a

