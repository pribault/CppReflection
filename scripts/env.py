#!/usr/bin/python3

import os

scriptDir = os.path.dirname(__file__)
rootDir = os.path.dirname(scriptDir)
includeDir = os.path.join(rootDir, "include")
srcDir = os.path.join(rootDir, "src")
buildDir = os.path.join(rootDir, "build")

print("root: %s" % rootDir)
print("script: %s" % scriptDir)
print("include: %s" % includeDir)
print("sources: %s" % srcDir)
