#!/bin/bash

TOPLEVEL=$(git rev-parse --show-toplevel)

function fail_no_command {
  echo "Failed to find ${1} in your \$PATH."
  exit 1
}

if ! command -v clang-format-diff.py >/dev/null; then
  fail_no_command clang-format-diff.py
fi

if ! command -v clang-format >/dev/null; then
  fail_no_command clang-format
fi

pushd "$TOPLEVEL" >/dev/null || exit
format_fixes=$(git diff -U0 --no-color --staged | clang-format-diff.py -p1)
popd >/dev/null || exit

if [ -z "${format_fixes}" ]; then
  exit 0
fi

echo "${format_fixes}" | colordiff

while read -r -p "Format issues detected by clang-format. Apply suggested fixes (yes/no)?" yn; do
  case $yn in
    [Yy]* )
      pushd "$TOPLEVEL" >/dev/null || exit
      echo "${format_fixes}" | git apply -p0 --index
      popd >/dev/null || exit
      break
      ;;
    [Nn]* ) exit ;;
    * ) echo "Please answer yes (y) or no (n)." ;;
  esac
done
