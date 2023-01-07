#!/usr/bin/python3

import getopt
import os
import re
import shutil
import sys
from env import *

# global variables
allowedBuildTypes = ["Release", "Debug"]
binDir = os.path.join(buildDir, "bin")

# print usage
def printUsage():
	print("runTests.py [-h] [--help] [-b <Debug|Release>] [--buildType <Debug|Release>]")
	print("  -h or --help: dysplay help and quit")
	print("  -b or --buildType: set build type ('Release' or 'Debug')")

if __name__ == '__main__':

	# define default variables
	buildType = "Release"

	# retrieve arguments
	opts, args = getopt.getopt(sys.argv[1:], "hb:", ["help", "buildType="])

	# ensure all arguments are parsed
	if len(args) != 0:
		print("invalid number of arguments (%s)" % (len(args) - 1))
		printUsage()
		exit(1)

	# handle each argument
	for opt, arg in opts:
		# help
		if opt in ("-h", "--help"):
			printUsage()
			exit(0)
		# build type
		if opt in ("-b", "--buildType"):
			if not arg in allowedBuildTypes:
				print("unknown build type '%s'" % arg)
				printUsage()
				exit(1)
			buildType = arg

	# make release
	print("Running unit tests for '%s' mode" % buildType)
	suffix = ""
	if sys.platform.startswith('win'):
		suffix = ".exe"
	result = os.system(os.path.join(binDir, buildType, "unit_tests" + suffix))
	if result:
		print("Unit tests KO!")
	else:
		print("Unit tests OK!")
	sys.exit(1 if result > 0 else 0)
