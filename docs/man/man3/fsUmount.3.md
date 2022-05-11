% FSMOUNT(3) fsMount 0.1.0
% Timothy Hutchins
% May 2022

# NAME
fsUmount - Unmount a filesystem

# SYNOPSIS
**#include <libmount/Mount.h>**\

**Mount myMount;**\

**int exit = myMount.fsUmount(std::string** *outDir***);**\
**int exit = myMount.fsUmount()**

# DESCRIPTION
This C++ function is used to unmount a filesystem on a linux system.

# OPTIONS
**fsUmount(std::string)** This call consists of one `std::string`, *outDir*.
This will unmount the inputed path.

## ARGUMENTS

*outDir*
: The directory of a mounted filesystem that you want to unmount.\


**fsUmount(void)**
This will unmount the last mounted filesystem that was mounted with the object.

## Arguments

**NONE**

# EXAMPLES
**myMount.fsUmount();**\
**myMount.fsUmount(***"/home/user/mountpoint"***);**\

# EXIT VALUES
**0**

: Success *EXIT_SUCCESS*

**-3**

: Insufficient privleges. User needs root. *Mount::NOROOT*

**-2**

: The mount point doesn't exist *Mount::MOUNTPOINTERR*


# COPYRIGHT

LICENSE GPLv3+: GNU GPL Version 3 or later <https:://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRENTY, to the extent permited by law.