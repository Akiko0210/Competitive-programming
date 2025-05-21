#!/bin/bash

echo "creating $@ ..."
mkdir "$@"
cd "$@"

cp ../template.cpp A.cpp
cp ../template.cpp B.cpp
cp ../template.cpp C.cpp
cp ../template.cpp D.cpp
cp ../template.cpp E.cpp
touch test