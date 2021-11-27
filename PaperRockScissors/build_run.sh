#!/bin/bash

readonly SCRIPT_DIR=$(cd $(dirname ${BASH_SOURCE[0]}) && pwd)
readonly OUTPUT_DIR=${SCRIPT_DIR}/build
CLEAN_BUILD=0
RUN_ONLY=1

function build
{
  mkdir -p ${OUTPUT_DIR}
  cd ${OUTPUT_DIR}

  cmake ${SCRIPT_DIR}
  make
}

function run
{
  cd ${OUTPUT_DIR}
  ./RockPaperScissors
}

function help
{
  cat << EOF
  Usage: $0 [-c|--clean]

  OPTIONS:
    -c|--clean
      A clean build. It is necessary if a different cmake generator is used (-m).

  Examples:
  1. A clean build and run.
     ./build_run.sh -c
  2. Only run
      ./build_run.sh -r
  3. No clean build and run
      ./build_run.sh
EOF
  exit 1
}


function parse_args
{
  key=$1
  case $key in
    -h|--help)
      help
    ;;
    -c|--clean)
      CLEAN_BUILD=1
    ;;
    -r|--run)
      RUN_ONLY=1
  esac
}

function main
{ 
  parse_args "$@"

  if [[ ${CLEAN_BUILD} == 1 ]]; then
    rm -rf ${OUTPUT_DIR}
  fi

  mkdir -p ${OUTPUT_DIR}
  cd ${OUTPUT_DIR}

  if [[${RUN_ONLY} == 1]]; then
    run
    exit
  fi

  build
  run
}

main "$@"