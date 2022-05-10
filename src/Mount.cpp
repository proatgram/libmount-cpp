/*
 * Mount.cpp
 *
 *  Created on: May 9, 2022
 *      Author: thetimbrick
 */

#include "Mount.h"

#include <filesystem>

const std::string Mount::READONLY = "ro";

const std::string Mount::READWRITE = "rw";

Mount::Mount()

{

}

Mount::~Mount() {

}

int Mount::fsMount(std::string fsDir, std::string outDir, int fsType, std::string accessType) {
	// Checks to see if we are running as root.
	// Root is required to use the `mount` command.
	if (geteuid() != 0) {
		return Mount::NOROOT;
	}
	// Checks to see if the file to mount exists.
	// If not, returns an error.
	if (!std::filesystem::exists(fsDir)) {
		return Mount::MOUNTFILEERR;
	}
	// Checks to see if the mount directory exists.
	// If not, returns an error.
	if (!std::filesystem::exists(outDir)) {
		return Mount::MOUNTPOINTERR;
	}
	// Update mount variables
	m_currentMountFS = Mount::m_getMountString(fsType);
	m_currentMountPoint = outDir;
	m_currentMountFSFile = fsDir;
	m_currentAccessType = accessType;

	std::string cmd;

	cmd.append("/usr/bin/mount -t ");
	cmd.append(m_currentMountFS);
	cmd.append(" -o ");
	cmd.append(m_currentAccessType);
	cmd.append(" ");
	cmd.append(m_currentMountFSFile);
	cmd.append(" ");
	cmd.append(m_currentMountPoint);

	if (system(cmd.c_str())) {
		return EXIT_FAILURE;
	}
	else {
		return EXIT_SUCCESS;
	}
}
/**
 *
 * @fn int fsUmount()
 * @brief Unmounts the currently STORED item.
 *
 * @return int
 */
int Mount::fsUmount() {
	// Checks to see if we are running as root.
	// ARoot is required to use the `umount` command
	if (geteuid() != 0) {
		return Mount::NOROOT;
	}

	// Checks to see if the mount point exists.
	if (!std::filesystem::exists(m_currentMountPoint)) {
		return Mount::MOUNTPOINTERR;
	}

	std::string cmd;

	cmd.append("/usr/bin/umount ");
	cmd.append(m_currentMountPoint);

	if (system(cmd.c_str()) == EXIT_SUCCESS) {
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}

std::string Mount::m_getMountString(int mountType) {
	switch (mountType) {
		case Mount::adfs:
			return "adfs";
			break;
		case Mount::affs:
			return "affs";
			break;
		case Mount::autofs:
			return "autofs";
			break;
		case Mount::cifs:
			return "cifs";
			break;
		case Mount::coda:
			return "coda";
			break;
		case Mount::coherent:
			return "coherent";
			break;
		case Mount::cramfs:
			return "cramfs";
			break;
		case Mount::debugfs:
			return "debugfs";
			break;
		case Mount::devpts:
			return "devpts";
			break;
		case Mount::efs:
			return "efs";
			break;
		case Mount::ext:
			return "ext";
			break;
		case Mount::ext2:
			return "ext2";
			break;
		case Mount::ext3:
			return "ext3";
			break;
		case Mount::ext4:
			return "ext4";
			break;
		case Mount::hfs:
			return "hfs";
			break;
		case Mount::hfsplus:
			return "hfsplus";
			break;
		case Mount::hpfs:
			return "hpfs";
			break;
		case Mount::iso9660:
			return "iso9660";
			break;
		case Mount::jfs:
			return "jfs";
			break;
		case Mount::minix:
			return "minix";
			break;
		case Mount::msdos:
			return "msdos";
			break;
		case Mount::ncpfs:
			return "ncpfs";
			break;
		case Mount::nfs:
			return "nfs";
			break;
		case Mount::nfs4:
			return "nfs4";
			break;
		case Mount::ntfs:
			return "ntfs";
			break;
		case Mount::proc:
			return "proc";
			break;
		case Mount::qnx4:
			return "qnx4";
			break;
		case Mount::ramfs:
			return "ramfs";
			break;
		case Mount::reiserfs:
			return "reiserfs";
			break;
		case Mount::romfs:
			return "romfs";
			break;
		case Mount::smbfs:
			return "smbfs";
			break;
		case Mount::squashfs:
			return "squashfs";
			break;
		case Mount::sysv:
			return "sysv";
			break;
		case Mount::tmpfs:
			return "tmpfs";
			break;
		case Mount::ubifs:
			return "ubifs";
			break;
		case Mount::udf:
			return "udf";
			break;
		case Mount::umsdos:
			return "umsdos";
			break;
		case Mount::usbfs:
			return "usbfs";
			break;
		case Mount::vfat:
			return "vfat";
			break;
		case Mount::xenix:
			return "xenix";
			break;
		case Mount::xfs:
			return "xfs";
			break;
		case Mount::xiafs:
			return "xiafs";
			break;
		default:
			return "NOTSUPPORTED";
			break;
	}
	return "NOTSUPPORTED";
}
