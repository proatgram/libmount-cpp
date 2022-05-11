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
	/**
	 * @fn int fsMount(std::string, std::string, int, std::string)
	 * @brief Mounts a filesystem
	 *
	 * @param fsDir The filesystem file, ex. `/dev/sdc`
	 * @param outDir The output or mountpoint directory. ex. `/home/user/mountpoint`
	 * @param fsType The Filesystem type. ex. "squashfs" `Mount::squashfs`
	 * @param accessType The access type. Read Only or Read Write. ex. `Mount::READWRITE` `Mount::READONLY`
	 * @return int
	 */
	int fsMount(std::string fsDir, std::string outDir, int fsType, std::string accessType);
	/**
	 * @fn int fsUmount(std::string)
	 * @brief Unmounts a mounted directory
	 *
	 * @param outDir The directory that is mounted to
	 * @return int
	 */
	int fsUmount(std::string outDir);
	/**
	 * @fn int fsUmount()
	 * @brief Unmounts the last mounted directory mounted with the object
	 *
	 * @return int
	 */
	int fsUmount();
	/* Error code for user having no root*/
	/**
	 * @brief NOROOT is the error return code for a user trying to use this without root
	 */
	static constexpr int NOROOT = -3;
	/* Error code for a mount point error. E.g. location doesn't exist*/
	/**
	 * @brief MOUNTPOINTERR is the error returned code for the mount point not existing
	 */
	static constexpr int MOUNTPOINTERR = -2;
	/* Error code for a filesystem file mount error. E.g. file doesn't exist*/
	/**
	 * @brief MOUNTFILEERR is the error return code for the file system mount not existing
	 */
	static constexpr int MOUNTFILEERR = -1;
	/* Readonly attribute*/
	/**
	 * @brief READONLY is the Read Only attribute
	 */
	static const std::string READONLY;
	/* Readwrite attribute*/
	/**
	 * @brief READWRITE is the Read and Write attribute
	 */
	static const std::string READWRITE;

	/* All the supported filesystem types */
	/**
	 * @enum
	 * @brief A list of all the supported filesystems. See mount(8) for more info.
	 *
	 */
	enum {
		adfs,    /**< adfs */
		affs,    /**< affs */
		autofs,  /**< autofs */
		cifs,    /**< cifs */
		coda,    /**< coda */
		coherent,/**< coherent */
		cramfs,  /**< cramfs */
		debugfs, /**< debugfs */
		devpts,  /**< devpts */
		efs,     /**< efs */
		ext,     /**< ext */
		ext2,    /**< ext2 */
		ext3,    /**< ext3 */
		ext4,    /**< ext4 */
		hfs,     /**< hfs */
		hfsplus, /**< hfsplus */
		hpfs,    /**< hpfs */
		iso9660, /**< iso9660 */
		jfs,     /**< jfs */
		minix,   /**< minix */
		msdos,   /**< msdos */
		ncpfs,   /**< ncpfs */
		nfs,     /**< nfs */
		nfs4,    /**< nfs4 */
		ntfs,    /**< ntfs */
		proc,    /**< proc */
		qnx4,    /**< qnx4 */
		ramfs,   /**< ramfs */
		reiserfs,/**< reiserfs */
		romfs,   /**< romfs */
		squashfs,/**< squashfs */
		smbfs,   /**< smbfs */
		sysv,    /**< sysv */
		tmpfs,   /**< tmpfs */
		ubifs,   /**< ubifs */
		udf,     /**< udf */
		ufs,     /**< ufs */
		umsdos,  /**< umsdos */
		usbfs,   /**< usbfs */
		vfat,    /**< vfat */
		xenix,   /**< xenix */
		xfs,     /**< xfs */
		xiafs    /**< xiafs */
	};

private:
	static std::string m_getMountString(int mountType);

	std::string m_currentMountPoint;
	std::string m_currentMountFS;
	std::string m_currentMountFSFile;
	std::string m_currentAccessType;
};



#endif /* INCLUDE_MOUNT_H_ */
