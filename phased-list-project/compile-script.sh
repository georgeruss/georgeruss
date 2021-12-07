#!/bin/bash

echo "/* COMPILE SCRIPT RUNNING *\\"

set -ex

javac -d bin -cp bin:phase2.jar src/cs1302/p2/*.java

check1302 src/cs1302/p2/*.java
