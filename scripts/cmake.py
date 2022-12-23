#!/usr/bin/python3

import getopt
import os
import sys
from env import *

# print usage
def printUsage():
	print("cmake.py [-h] [--help] [-d] [--dynamic] [-s] [--static]")
	print("  -h or --help: dysplay help and quit")
	print("  -d or --dynamic: enable dynamic linking (default)")
	print("  -s or --static: disable dynamic linking")

if __name__ == '__main__':

	# define default variables
	dynamicLinking = True

	# retrieve arguments
	opts, args = getopt.getopt(sys.argv[1:], "hds", ["help", "dynamic", "static"])

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
		elif opt in ("-d", "--dynamic"):
			dynamicLinking = True
		elif opt in ("-s", "--static"):
			dynamicLinking = False

	# run cmake command
	print("starting cmake")
	os.system("cmake %s -DENABLE_DYNAMIC_LINK=%s -DCMAKE_TOOLCHAIN_FILE=%s/scripts/buildsystems/vcpkg.cmake -B %s" % (rootDir, str(dynamicLinking), vcpkgPath, buildDir))
	print("cmake ended!")
