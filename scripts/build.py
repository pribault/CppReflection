#!/usr/bin/python3

import getopt
import os
import sys
from env import *

allowedBuildTypes = ["Release", "Debug"]

# print usage
def printUsage():
	print("build.py [-h] [--help] [-b <Debug|Release>] [--buildType <Debug|Release>]")
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

	# run build command
	print("starting '%s' build" % buildType)
	os.system("cmake --build %s --config %s" % (buildDir, buildType))
	print("build ended!")
