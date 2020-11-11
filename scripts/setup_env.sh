#!/bin/bash

mkdir logs build .obj 2> /dev/null

if echo $(uname) | grep -i "darwin" > /dev/null
then
	sed -i '' "s/42mPASS/0;32mPASS/g" unity/src/unity.c
	sed -i '' "s/42mFAIL/0;31mFAIL/g" unity/src/unity.c
	sed -i '' "s/42mOK/0;32mOK/g" unity/src/unity.c
else
	sed -i "s/42mPASS/0;32mPASS/g" unity/src/unity.c
	sed -i "s/42mFAIL/0;31mFAIL/g" unity/src/unity.c
	sed -i "s/42mOK/0;32mOK/g" unity/src/unity.c
fi
