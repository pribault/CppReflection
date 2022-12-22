#!/usr/bin/python3

import os
from env import *

os.system("cmake --build %s" % buildDir)
