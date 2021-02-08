#!/bin/bash

echo -e "\e[7m======== Starting tests ========\e[0m"

src="tcsh"
dst="./42sh"

cmds=(ls test exit "cd;ls")
passed=0

for i in "${cmds[@]}"
do
    echo -e "\e[7mTrying $i\e[0m"
    if diff -u --color=always --label $src --label $dst <(echo "$i" | $src) <(echo "$i" | $dst)
    then
        echo -e "\e[32mPassed $i\e[0m"
        passed=$((passed + 1))
    else
        echo -e "\e[91mFailed $i\e[0m"
    fi
done

echo -e "\e[7m======== Finished tests ========\e[0m"
echo -e "Passed $passed/${#cmds[@]} tests\n"
