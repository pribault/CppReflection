#!/usr/bin/python3

import getopt
import os
import sys
from env import *

# print usage
def printUsage():
	print("cmake.py [-h] [--help]")

if __name__ == '__main__':

	# retrieve arguments
	opts, args = getopt.getopt(sys.argv[1:], "h", ["help"])

	# ensure all arguments are parsed
	if len(args) != 0:
		print("invalid number of arguments (%s)" % (len(args) - 1))
		printUsage()
		exit(1)

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

	# run cmake command
	print("starting cmake")
	os.system("cmake %s -DCMAKE_TOOLCHAIN_FILE=%s/scripts/buildsystems/vcpkg.cmake -B %s" % (rootDir, vcpkgPath, buildDir))
	print("cmake ended!")
