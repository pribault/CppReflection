#!/usr/bin/python3

import os
from env import *

os.system("cmake %s -B %s" % (rootDir, buildDir))
