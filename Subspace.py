#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#--------------------------------------------------------------
#
# IntelUniq
#               -- Intelligence shall be unique 
#
# Subspace.py: #TODO DESC HERE
#
#--------------------------------------------------------------
#
# Date:     2015-05-12
#
# Author:   gewu@baidu.com
#
#

#--------------------------------------------------------------
# Globl Constants & Functions
#--------------------------------------------------------------

#--------------------------------------------------------------
# Classes
#--------------------------------------------------------------
class Subspace(object):
    
    def __init__(self):
        pass

    def subspace(self, lstr):
        return lstr.replace(" ", "%20")
    


if __name__ == "__main__":

    ss = Subspace()
    print ss.subspace("We are happy")


