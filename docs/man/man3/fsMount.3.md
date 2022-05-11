% FSMOUNT(3) fsMount 0.1.0
% Timothy Hutchins
% May 2022

# NAME
fsMount - Mount a filesystem

# SYNOPSIS
**#include <libmount/Mount.h>**\

**Mount myMount;**\

**int exit = myMount.fsMount(std::string** *fsDir***, std::string** *outDir***, int** *fsType***, std::string** *accessType***);**\

# DESCRIPTION
This C++ function is used to mount a filesystem on a linux system. The filetypes and filesystems that it can mount are the same as mount. See mount(8) for details.

# OPTIONS
**fsMount()** This call consists of three std::strings, fsDir, outDir, and accessType, and one int, fsType.\

## ARGUMENTS

*fsDir*
: The filesystem file or directory that you want to mount. For example, `/dev/sdc`\
*outDir*
: The output directory where you want the filesystem to be mounted. For example, `/home/user/mountpoint`\
*fsType*
: The filesytem type. All that are supported by mount(8) are supported. For example, `Mount::squashfs` would be squashfs\
*accessType*
: The access type. either read only or read write. For example, `Mount::READWRITE` would mount as read and write\

# EXAMPLES
**myMount.fsMount(***"/dev/sde"***, ***"/home/user/mountPoint"***, ***Mount::ntfs***, ***Mount::READWRITE***);**\

# EXIT VALUES
**0**

: Success *EXIT_SUCCESS*

**-3**

: Insufficient privleges. User needs root. *Mount::NOROOT*

**-2**

: The mount point doesn't exist *Mount::MOUNTPOINTERR*

**-1**

: The filesystem file doesn't exist *Mount::MOUNTFILEERR*

# COPYRIGHT

LICENSE GPLv3+: GNU GPL Version 3 or later <https:://gnu.org/licenses/gpl.html>. This is free software: you are free to change and redistribute it. There is NO WARRENTY, to the extent permited by law.