#!/bin/bash

set -e

bin_name="util-template"
bin_dir=~/bin
dest_bin_path="$bin_dir/$bin_name"

color() {
	local -r color="${1}"
	case "${color}" in
		'red')
			printf '%b' '\e[1;31m'
			;;
		'green')
			printf '%b' '\e[1;32m'
			;;
		'yellow')
			printf '%b' '\e[1;33m'
			;;
		*)
			>&2 printf 'INVALID COLOR'
			exit
	esac
	shift
	"${@}"
	printf '%b' '\e[0m'
}

color yellow  printf "== BUILDING...==\n"

make run
color green printf "\n== BUILD COMPLETE ==\n\n"


color yellow  printf "== DEPLOYING... ==\n"
printf "Copying %s binary to %s dir...\n" "$bin_name" "$dest_bin_path"
[ -e $dest_bin_path ] && rm $dest_bin_path

cp ./bin/$bin_name $dest_bin_path
printf "Copied %s to %s dir...\n" "$bin_name" "$dest_bin_path"
color green  printf "== DEPLOY COPMPLETE ==\n\n"

color yellow  printf "== TESTING %s ==\n" "$dest_bin_path"
$dest_bin_path -h
printf "\n\n"
