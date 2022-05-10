/*
 * Mount.h
 *
 *  Created on: May 9, 2022
 *      Author: thetimbrick (Timothy Hutchins)
 */

#ifndef INCLUDE_MOUNT_H_
#define INCLUDE_MOUNT_H_

#include <string>
#include <unistd.h>
#include <filesystem>

class Mount {
public:
	Mount();

	~Mount();

	int fsMount(std::string fsDir, std::string outDir, int fsType, std::string accessType);

	int fsUmount(std::string outDir);

	int fsUmount();

	static constexpr int NOROOT = -3;

	static constexpr int MOUNTPOINTERR = -2;

	static constexpr int MOUNTFILEERR = -1;

	static const std::string READONLY;

	static const std::string READWRITE;

	enum {
		adfs,
		affs,
		autofs,
		cifs,
		coda,
		coherent,
		cramfs,
		debugfs,
		devpts,
		efs,
		ext,
		ext2,
		ext3,
		ext4,
		hfs,
		hfsplus,
		hpfs,
		iso9660,
		jfs,
		minix,
		msdos,
		ncpfs,
		nfs,
		nfs4,
		ntfs,
		proc,
		qnx4,
		ramfs,
		reiserfs,
		romfs,
		squashfs,
		smbfs,
		sysv,
		tmpfs,
		ubifs,
		udf,
		ufs,
		umsdos,
		usbfs,
		vfat,
		xenix,
		xfs,
		xiafs
	};

private:
	static std::string m_getMountString(int mountType);

	std::string m_currentMountPoint;
	std::string m_currentMountFS;
	std::string m_currentMountFSFile;
	std::string m_currentAccessType;
};



#endif /* INCLUDE_MOUNT_H_ */
