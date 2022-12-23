#!/usr/bin/python3

import getopt
import os
import sys
from env import *

allowedBuildTypes = ["Release", "Debug"]

# print usage
def printUsage():
	print("cmake.py [-h] [--help] [-d] [--dynamic] [-s] [--static] [-b <Debug|Release>] [--buildType <Debug|Release>]")
	print("  -h or --help: dysplay help and quit")
	print("  -d or --dynamic: enable dynamic linking (default)")
	print("  -s or --static: disable dynamic linking")
	print("  -b or --buildType: set build type ('Release' or 'Debug')")

if __name__ == '__main__':

	# define default variables
	dynamicLinking = True
	buildType = "Release"

	# retrieve arguments
	opts, args = getopt.getopt(sys.argv[1:], "hdsb:", ["help", "dynamic", "static", "buildType="])

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
		# build type
		if opt in ("-b", "--buildType"):
			if not arg in allowedBuildTypes:
				print("unknown build type '%s'" % arg)
				printUsage()
				exit(1)
			buildType = arg

	# run cmake command
	print("starting cmake")
	os.system("cmake %s -DENABLE_DYNAMIC_LINK=%s -DCMAKE_TOOLCHAIN_FILE=%s/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=%s -B %s" % (rootDir, str(dynamicLinking), vcpkgPath, buildType, buildDir))
	print("cmake ended!")
