#!/usr/bin/python3

import os
import re
import shutil
import sys
from env import *

# global variables
releaseDir = os.path.join(buildDir, "release")
releaseIncludeDir = os.path.join(releaseDir, "include")
releaseBinDir = os.path.join(releaseDir, "bin")
releaseLibDir = os.path.join(releaseDir, "lib")

# filter strings with the given pattern
def glob_re(pattern, strings):
	regex = re.compile(pattern)
	return filter(regex.match, strings)

# copy files matching the given pattern from srcDir to dstDir
def copy(srcDir, pattern, dstDir):
	# ensure dst directory exists
	if not os.path.exists(dstDir):
		os.makedirs(dstDir)
	# iterate over files matching pattern
	for file in glob_re(pattern, os.listdir(srcDir)):
		srcFile = os.path.join(srcDir, file)
		dstFile = os.path.join(dstDir, file)
		# copy file or directory
		if os.path.isdir(srcFile):
			shutil.copytree(srcFile, dstFile, dirs_exist_ok=True)
		else:
			shutil.copy(srcFile, dstFile)

# platform independant steps to make release
def releaseCommon():
	# ensure release directory exists
	if not os.path.exists(releaseDir):
		os.makedirs(releaseDir)
	# copy includes
	copy(includeDir, "^.+$", releaseIncludeDir)

# windows specific steps to make release
def releaseWindows():
	binDir = os.path.join(buildDir, "bin", "Release")
	copy(binDir, "^.+\\.(?P<ext>exe|dll)$", releaseBinDir)
	copy(binDir, "^.+\\.(?P<ext>lib)$", releaseLibDir)

# unix specific steps to make release
def releaseUnix():
	binDir = os.path.join(buildDir, "bin")
	copy(binDir, "^\\w+$", releaseBinDir)
	copy(binDir, "^.+\\.(?P<ext>so|a)$", releaseLibDir)

# make release
releaseCommon()
if sys.platform.startswith('win'):
	releaseWindows()
else:
	releaseUnix()
